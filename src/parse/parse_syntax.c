/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 21:12:59 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/08 14:08:41 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char				*have_target(char *syntax_flag, char chr)
{
	char				flag;

	flag = 0;
	if (chr == '<' || chr == '>')
		flag = 1;
	else if (chr == '|')
		flag = 2;
	else if (*syntax_flag && chr == ';')
		return (set_error_code(142));
	else
		*syntax_flag = 0;
	if (flag)
	{
		if (((*syntax_flag & flag) == flag) || ((*syntax_flag & 1) == 1))
			return (set_error_code(142));
		else
			*syntax_flag |= flag;
	}
	else
		*syntax_flag = 0;
	return (syntax_flag);
}

char					*syntax(t_dlist *dlist)
{
	char				syntax_flag;
	char				*token;

	syntax_flag = 0;
	while (dlist)
	{
		token = (char *)dlist->content;
		if (!have_target(&syntax_flag, *token))
			return (set_error_code(135));
		dlist = dlist->next;
	}
	if (syntax_flag)
		return (set_error_code(142));
	return (token);
}
