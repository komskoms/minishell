/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:27:36 by jihoon            #+#    #+#             */
/*   Updated: 2021/05/29 17:27:53 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	fill_tokens_each(t_dlist **lst, t_dlist *token, char *type)
{
	t_dlist		*lst_on;
	int			i;

	i = 0;
	while (token)
	{
		if (is_token_type(token, type))
		{
			lst_on->next = 0;
			i++;
		}
		else
		{
			lst_on = add_to_last_token(lst + i, get_token_type(token),
									get_token_content(token));
			if (!lst_on)
				return (0);
		}
		token = token->next;
	}
	lst[++i] = 0;
	return (1);
}

t_dlist		**split_tokens_by_type(t_dlist *tokens_head, char *type)
{
	t_dlist		**new_list;
	int			count;

	count = 1 + count_token_match_type(tokens_head, type);
	new_list = ft_calloc(count + 1, sizeof(t_dlist *));
	if (!fill_tokens_each(new_list, tokens_head, type))
	{
		dlist_clear(new_list, &del_wrap);
		return (0);
	}
	return (new_list);
}

void		list_tokens_clear(t_dlist **list_tokens)
{
	t_dlist		*tmp;

	while (*list_tokens)
	{
		tmp = (*list_tokens)->next;
		dlist_clear((t_dlist **)&(*list_tokens)->content, &del_wrap);
		*list_tokens = tmp;
	}
}
