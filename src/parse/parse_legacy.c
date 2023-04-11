/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_legacy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 07:52:23 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/06 16:59:56 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				no_point_but_norm(void **cmd)
{
	if (cmd)
		cmd = 0;
}

t_dlist				*get_env_var_hashmap(t_mshl *mshl, char *key)
{
	t_dlist			*match;

	match = hashmap_pick(mshl->env_hashmap, key);
	if (!match)
		match = hashmap_pick(mshl->var_hashmap, key);
	return (match);
}

int					get_key_size(char *content)
{
	int				offset;

	offset = 0;
	if (!content)
		return (offset);
	if (*content == '?')
		return (1);
	if (!ft_isalpha(*content) && *content != '_')
		return (offset);
	while (ft_isalnum(content[offset]) || content[offset] == '_')
		offset++;
	return (offset);
}

void				*exchange_sp_param(
				char **exchange, t_mshl *mshl, char *token)
{
	if (token[0] == '?')
	{
		return (replace((void **)exchange, ft_itoa(mshl->proc.last_exitcode)));
	}
	return (NULL);
}

void				takeoff_all_decorate(t_mshl *mshl)
{
	t_dlist			*head;
	t_dlist			*element;
	t_wrap			*wrap;
	int				is_export;

	head = mshl->tokens;
	while (head)
	{
		element = head->content;
		if (element)
		{
			wrap = (t_wrap *)element->content;
			is_export = !ft_strncmp((char *)wrap->content, "export", 7);
			while (element)
			{
				wrap = (t_wrap *)element->content;
				takeoff_decorate((char *)wrap->content);
				if (is_export)
					wrap->type = MS_CMD;
				element = element->next;
			}
		}
		head = head->next;
	}
}
