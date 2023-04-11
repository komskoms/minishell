/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:21:35 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/08 15:25:11 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void					set_group_flag(char *quote_flag, char command)
{
	char				*group_addr;

	if ((*(quote_flag + 1) & 1) == 1)
	{
		*(quote_flag + 1) = (*(quote_flag + 1) << 1);
		return ;
	}
	if (command == *IGNORE && !(*(quote_flag + 1) & 1))
	{
		*(quote_flag + 1) = 1;
		return ;
	}
	*(quote_flag + 1) = (*(quote_flag + 1) << 1);
	group_addr = ft_strchr(GROUP, (int)command);
	if (group_addr)
	{
		if (*quote_flag == *group_addr)
			*quote_flag = 0;
		else if (!*quote_flag)
			*quote_flag = *group_addr;
	}
}

static void				*append_element(char **element, char command)
{
	char				append[2];

	append[1] = 0;
	append[0] = command;
	if (!*element)
	{
		if (!replace((void **)element, ft_strdup(append)))
			return (set_error_code(135));
	}
	else if (!replace((void **)element, ft_strjoin(*element, append)))
		return (set_error_code(135));
	return (*element);
}

static void				*add_element(t_dlist **element_list, char **element)
{
	t_dlist				*new_list;

	new_list = NULL;
	if (!*element)
		return (element_list);
	if (**element)
	{
		if (!replace((void **)&new_list, dlist_new(*element)))
			return (set_error_code(135));
		dlist_add_last(element_list, new_list);
		*element = NULL;
	}
	return (new_list);
}

static void				*is_closed(char *quote_flag, t_dlist **element_list)
{
	if ((*(quote_flag + 1) & 1))
		return (set_error_code(131));
	if (*quote_flag)
		return (set_error_code(132));
	return (*element_list);
}

void					*split_element(char **command, t_dlist **element_list)
{
	char				*new_element;
	char				quote_flag[2];

	if (!command || !*command)
		return (set_error_code(135));
	new_element = NULL;
	ft_memset(quote_flag, 0, 2);
	while (**command)
	{
		set_group_flag(quote_flag, **command);
		if ((!ft_strchr(SPACE, **command) || *quote_flag ||
			(!(quote_flag[1] & 1) && quote_flag[1] & 2)))
		{
			if (!append_element(&new_element, **command))
				return (set_error_code(135));
		}
		else if (!add_element(element_list, &new_element))
			return (set_error_code(135));
		*command += 1;
	}
	if (new_element && !add_element(element_list, &new_element))
		return (set_error_code(135));
	return (is_closed(quote_flag, element_list));
}
