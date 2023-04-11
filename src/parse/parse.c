/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:37:13 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/09 10:30:59 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void					drop_order(t_mshl *mshl)
{
	t_dlist				*current_order;

	if (!mshl)
		return ;
	while (mshl->tokens)
	{
		current_order = mshl->tokens;
		dlist_clear((t_dlist **)&current_order->content, del_wrap);
		mshl->tokens = mshl->tokens->next;
		free(current_order);
	}
}

void					drop_mshl(t_mshl *mshl)
{
	if (!mshl)
		return ;
	drop_order(mshl);
	hashmap_clear((t_hashmap **)&mshl->var_hashmap);
	hashmap_clear((t_hashmap **)&mshl->env_hashmap);
	dlist_clear((t_dlist **)&mshl->history, del_content);
}

int						dispose_history(t_mshl *mshl)
{
	t_dlist				*del;

	if (!dlist_add_front(&mshl->history, dlist_new((void *)mshl->line)))
		return (int_set_error_code(135, 0));
	mshl->history_size++;
	mshl->line = NULL;
	if (MAX_HISTORY_SIZE < mshl->history_size)
	{
		del = mshl->history;
		while (del->next)
			del = del->next;
		if (del->prev)
		{
			del->prev->next = NULL;
			free(del->content);
			free(del);
			return (1);
		}
		return (int_set_error_code(145, 0));
	}
	return (1);
}

static void				*parse_body(t_mshl *mshl, char *command)
{
	t_dlist				*dlist;
	t_dlist				*wrap_list;

	dlist = NULL;
	if (!split_element(&command, &dlist) || !split_token(dlist) ||
		!syntax(dlist))
	{
		dlist_clear(&dlist, del_content);
		return (NULL);
	}
	if (!route_parse(&dlist, &wrap_list))
	{
		dlist_clear(&wrap_list, del_wrap);
		dlist_clear(&dlist, del_content);
		return (NULL);
	}
	if (!split_semicolon(mshl, &wrap_list))
	{
		dlist_clear(&wrap_list, del_wrap);
		return (NULL);
	}
	return (mshl);
}

void					*parse(t_mshl *mshl)
{
	char				*command;

	if (!mshl->line)
		return (set_error_code(135));
	if (!*mshl->line)
	{
		free(mshl->line);
		return (set_error_code(0));
	}
	if (!dispose_history(mshl))
		return (set_error_code(135));
	command = (char *)mshl->history->content;
	if (*command == ';')
		return (set_error_code(134));
	if (!parse_body(mshl, command))
		return (NULL);
	takeoff_all_decorate(mshl);
	return (mshl);
}
