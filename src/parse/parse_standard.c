/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_standard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 03:46:57 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/01 10:50:46 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void				takeoff_quote(char *str, char *quote, char *str_quote)
{
	ft_memcpy(str, str + 1, ft_strlen(str));
	if (!*quote)
		*quote = *str_quote;
	else
		*quote = 0;
}

void					takeoff_decorate(char *str)
{
	char				*str_quote;
	char				quote;

	quote = 0;
	while (*str)
	{
		str_quote = ft_strchr(GROUP, *str);
		if (str_quote && (!quote || (quote && (*str_quote == quote))))
			takeoff_quote(str, &quote, str_quote);
		else if (*str == *IGNORE)
		{
			ft_memcpy(str, str + 1, ft_strlen(str));
			str++;
		}
		else
			str++;
	}
}
