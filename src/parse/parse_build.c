/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 14:05:17 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/07 21:30:38 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void				set_type(char **type, char *content, char *file_flag)
{
	if (!ft_strncmp(content, ">>", ft_strlen(content)) ||
		!ft_strncmp(content, ">", ft_strlen(content)) ||
		!ft_strncmp(content, "<", ft_strlen(content)))
	{
		*type = MS_REDIR;
		*file_flag = 1;
	}
	else if (!ft_strncmp(content, "|", ft_strlen(content)))
		*type = MS_PIPE;
	else if (!ft_strncmp(content, ";", ft_strlen(content)))
		*type = MS_SEMICOLON;
	else if (*file_flag)
	{
		*type = MS_FILE;
		*file_flag = 0;
	}
	else if (is_env(content))
		*type = MS_ENV;
	else
		*type = MS_CMD;
}

static void				*is_open(char *file_flag)
{
	if (*file_flag)
		return (set_error_code(130));
	return (file_flag);
}

void					*route_parse(t_dlist **token, t_dlist **wrap_list)
{
	t_wrap				*wrap;
	char				file_flag;

	file_flag = 0;
	*wrap_list = NULL;
	while (*token)
	{
		if (!init((void **)&wrap, sizeof(t_wrap)))
		{
			if ((*token)->prev)
				(*token)->prev->next = NULL;
			return (set_error_code(135));
		}
		wrap->content = (*token)->content;
		set_type(&wrap->type, wrap->content, &file_flag);
		(*token)->content = wrap;
		if (!*wrap_list)
			*wrap_list = *token;
		*token = (*token)->next;
	}
	return (is_open(&file_flag));
}

void					del_wrap(void *content)
{
	t_wrap				*wrap;

	if (!content)
		return ;
	wrap = (t_wrap *)content;
	if (wrap)
	{
		if (wrap->content)
		{
			free(wrap->content);
		}
		free(wrap);
	}
}
