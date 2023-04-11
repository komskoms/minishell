/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:08:01 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/01 09:12:45 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t			search_slice_position(char *content)
{
	size_t				offset;
	char				quote_flag[2];

	offset = 0;
	ft_memset(quote_flag, 0, 2);
	while (*content)
	{
		set_group_flag(quote_flag, *content);
		if (!*quote_flag &&
				(*content == *SEPERATOR || ft_strchr(ASC_COMMAND, *content)))
			return (offset);
		++content;
		++offset;
	}
	return (0);
}

static void				*slice_element(t_dlist *target, size_t offset)
{
	char				*new_element;
	char				*current_element;

	if (ft_strlen(target->content) == offset)
		return (target->content);
	current_element = target->content;
	target->content = ft_substr(current_element, 0, offset);
	new_element = ft_strdup(current_element + offset);
	free(current_element);
	if (!target->content || !new_element)
		return (set_error_code(135));
	return (new_element);
}

static void				*insert_token(t_dlist *tok_list, char *insert_content)
{
	t_dlist				*insert_dlist;

	if (insert_content == tok_list->content)
		return (tok_list);
	if (!insert_content)
		return (set_error_code(135));
	insert_dlist = dlist_new(insert_content);
	if (insert_dlist)
	{
		insert_dlist->next = tok_list->next;
		if (tok_list->next)
			insert_dlist->next->prev = insert_dlist;
		insert_dlist->prev = tok_list;
		tok_list->next = insert_dlist;
	}
	return (insert_dlist);
}

static void				*dispose_asc_command(t_dlist *tok_list)
{
	char				letter[1];
	size_t				offset;

	letter[0] = ((char *)tok_list->content)[0];
	offset = 0;
	if (ft_strchr(ASC_COMMAND, *letter))
	{
		++offset;
		if (*letter == '>' && *letter == ((char *)tok_list->content)[1])
			++offset;
	}
	else if (*letter == *SEPERATOR)
	{
		++offset;
	}
	if (offset && !insert_token(tok_list, slice_element(tok_list, offset)))
		return (set_error_code(135));
	return (tok_list);
}

void					*split_token(t_dlist *element_list)
{
	size_t				offset;
	t_dlist				*temp;

	temp = element_list;
	while (element_list)
	{
		offset = search_slice_position(element_list->content);
		if (offset)
		{
			if (!insert_token(element_list,
										slice_element(element_list, offset)))
				return (set_error_code(135));
		}
		else if (!dispose_asc_command(element_list))
			return (set_error_code(135));
		element_list = element_list->next;
	}
	return (temp);
}
