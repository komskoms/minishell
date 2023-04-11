/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 07:41:57 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/01 04:13:51 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				get_next_line(int fd, char **line)
{
	static char	*data[CUSTOM_OPEN_MAX];

	if (read(fd, "", 0) < 0 || !line || BUFFER_SIZE < 1)
	{
		return (-1);
	}
	return (dispose_string(fd, &data[fd], line, 0));
}
