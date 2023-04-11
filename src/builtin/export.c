/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:03:52 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/07 14:56:24 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_struct.h"
#include "minishell.h"

int						is_env(char *content)
{
	int					offset;

	offset = is_key(content);
	if (offset == (int)ft_strlen(content))
		offset = 0;
	return (offset);
}

int						is_key(char *content)
{
	int					offset;

	offset = 0;
	if (!ft_isalpha(*content) && *content != '_')
		return (0);
	while (*content)
	{
		if (!ft_isalnum(*content) && *content != '_' && *content != '=')
			return (0);
		if (*content == '=')
			return (offset);
		content++;
		offset++;
	}
	return (offset);
}

static int				dispose_loop(t_mshl *mshl, char **argv)
{
	t_pair				*e_pair;
	t_pair				*pair;
	int					index;

	index = 1;
	while (argv[index])
	{
		e_pair = NULL;
		if (!replace((void **)&e_pair, new_pair(argv[index])))
			return (int_set_error_code(135, 1));
		pair = hashmap_pop(mshl->var_hashmap, argv[index]);
		if (e_pair->key_length == ft_strlen(argv[index]))
		{
			if (pair)
				hashmap_update(mshl->env_hashmap, pair);
			pair_clear(e_pair);
		}
		else
		{
			pair_clear(pair);
			hashmap_update(mshl->env_hashmap, e_pair);
		}
		index++;
	}
	return (0);
}

int						builtin_export(void *pack, char **argv)
{
	t_mshl				*mshl;

	mshl = (t_mshl *)pack;
	if (argv && !argv[1])
		print_hashmap(mshl->env_hashmap, "declare -x ");
	else
		return (dispose_loop(mshl, argv));
	return (0);
}
