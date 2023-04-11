/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:17:12 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/07 22:33:57 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>
#include <string.h>
#include <fcntl.h>

static char				*get_index_line(int fd, char **line, int index)
{
	int					result;

	if (index < 0)
		return (NULL);
	while (1)
	{
		result = get_next_line(fd, line);
		if (result < 0)
			return (NULL);
		if (!result && index)
			return (NULL);
		if (!index)
			return (*line);
		free(*line);
		index--;
	}
}

void					dispose_error(void)
{
	char				*err_str;
	int					fd;

	if (129 < errno)
	{
		fd = open("error", O_RDONLY);
		if (!get_index_line(fd, &err_str, (errno - CUSTOM_ERROR_CODE)))
			err_str = ft_strdup("cant open [error] file or not defined error");
		close(fd);
	}
	else
	{
		if (!errno)
			return ;
		err_str = strerror(errno);
		if (err_str)
			err_str = ft_strdup(err_str);
		else
			err_str = ft_strdup("cant open [error] file or not defined error");
	}
	ft_putstr_fd("minishell: ", 2);
	ft_putendl_fd(err_str, 2);
	free(err_str);
}

void					*set_error_code(int error_code)
{
	if (CUSTOM_ERROR_CODE <= error_code)
	{
		if (error_code != 135)
			errno = error_code;
	}
	return (NULL);
}

int						int_set_error_code(int error_code, int response)
{
	if (CUSTOM_ERROR_CODE <= error_code)
	{
		if (error_code != 135)
			errno = error_code;
	}
	return (response);
}
