/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split_semicolon.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:45:29 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/07 21:00:29 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			skip_string(char *token, int offset)
{
	int				single_q;

	single_q = 0;
	while (token[offset] &&
		(token[offset] != '$' || single_q || token[offset] == '\\'))
	{
		if (token[offset] == '\\')
			offset++;
		if (token[offset] == '\'')
			single_q = !single_q;
		offset++;
	}
	return (offset);
}

static void			*exchange_env(t_dlist *dest, t_mshl *mshl)
{
	char			*token;
	int				offset;

	offset = 0;
	token = (char *)((t_wrap *)dest->content)->content;
	while (token[offset])
	{
		offset = skip_string(token, offset);
		if (token[offset])
		{
			offset = exchange_key_to_value(dest, mshl, offset);
			token = (char *)((t_wrap *)dest->content)->content;
			if (offset < 0)
				return (NULL);
		}
	}
	return (dest);
}

static t_dlist		*get_after_semicolon(t_mshl *mshl, t_dlist *list)
{
	t_dlist			*new_head;
	t_dlist			*current_head;

	current_head = list;
	while (list)
	{
		if (*((t_wrap *)list->content)->type == *MS_SEMICOLON)
		{
			new_head = list->next;
			if (new_head)
				new_head->prev = NULL;
			if (list->prev)
				list->prev->next = NULL;
			transform_env(current_head);
			del_wrap(list->content);
			free(list);
			return (new_head);
		}
		exchange_env(list, mshl);
		list = list->next;
	}
	transform_env(current_head);
	return (set_error_code(135));
}

void				*split_semicolon(t_mshl *mshl, t_dlist **dlist)
{
	t_dlist			*new;
	t_dlist			*head;
	t_wrap			*wrap;

	head = *dlist;
	while (1)
	{
		if (!init((void **)&new, sizeof(t_dlist)))
			return (set_error_code(135));
		new->content = head;
		wrap = (t_wrap *)head->content;
		if (*(char *)wrap->type == *MS_CMD && *(char *)wrap->content != '$')
			ft_tolower_str((char *)((t_wrap *)head->content)->content);
		dlist_add_last((t_dlist **)&mshl->tokens, new);
		head = get_after_semicolon(mshl, head);
		if (!head)
			break ;
		if (*((t_wrap *)head->content)->type == *MS_SEMICOLON ||
			*((t_wrap *)head->content)->type == *MS_PIPE)
		{
			*dlist = head;
			return (set_error_code(142));
		}
	}
	return (mshl);
}
