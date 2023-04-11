/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exchange.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:16:02 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/04 21:21:13 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*get_key(char *src, int offset, int size)
{
	char		*key;

	key = NULL;
	if (!replace((void **)&key, ft_substr(src, offset, size)))
		return (set_error_code(135));
	return (key);
}

static t_pair	*fill_pair(t_mshl *mshl, t_pair *pair)
{
	t_dlist		*target;
	char		*value;
	void		*sp_result;

	target = get_env_var_hashmap(mshl, (char *)pair->key);
	value = "";
	if (!ft_isalpha(*(char *)pair->key) && *(char *)pair->key != '_')
	{
		sp_result =
			exchange_sp_param((char **)&pair->val, mshl, (char *)pair->key);
		return (sp_result);
	}
	if (target)
		value = ((t_pair *)target->content)->val;
	if (!replace((void **)&pair->val, ft_strdup(value)))
		return (set_error_code(135));
	return (pair);
}

static int		set_err_return_int(int error_code)
{
	set_error_code(error_code);
	return (-1);
}

int				exchange_key_to_value(t_dlist *dest, t_mshl *mshl, int offset)
{
	int			key_size;
	char		*token;
	t_pair		*pair;

	pair = NULL;
	token = (char *)((t_wrap *)dest->content)->content;
	if (!replace((void **)&pair, new_pair("")))
		return (set_err_return_int(135));
	key_size = get_key_size(&(token[offset + 1]));
	if (!replace((void **)&pair->key, get_key(token, offset + 1, key_size)))
		return (set_err_return_int(135));
	if (!fill_pair(mshl, pair))
		return (-1);
	token[offset] = 0;
	if (!replace((void **)&pair->val,
			ft_strjoin((char *)pair->val, &(token[offset + key_size + 1]))))
		return (set_err_return_int(135));
	if (!replace((void **)&pair->val, ft_strjoin(token, (char *)pair->val)))
		return (set_err_return_int(135));
	free(token);
	((t_wrap *)dest->content)->content = pair->val;
	pair->val = NULL;
	pair_clear(pair);
	return (offset);
}
