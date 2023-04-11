/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 07:41:43 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/05/28 17:01:10 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_memncpy(char *dest, char *src, int n)
{
	while (src && n-- && *src)
	{
		*dest++ = *src++;
	}
	*dest = 0;
}

char			*ft_strnncat(char *s1, char *s2, int n1, int n2)
{
	char		*new;

	if (!(new = (char *)malloc(n1 + n2 + 1)))
	{
		return (NULL);
	}
	ft_memncpy(new, s1, n1);
	ft_memncpy(new + n1, s2, n2);
	return (new);
}

char			*gnl_set_data(char **out, char *src)
{
	if (*out)
	{
		free(*out);
	}
	*out = src;
	return (*out);
}

int				cut_string(char **data, char **line, int offset, int last)
{
	if (!(*line = ft_strnncat(*data, NULL, offset, 0)))
	{
		gnl_set_data(data, NULL);
		return (-1);
	}
	if (*data && !last)
	{
		ft_memncpy(*data, *data + offset + 1, -1);
	}
	if (last)
	{
		gnl_set_data(data, NULL);
	}
	return (1);
}

int				dispose_string(int fd, char **data, char **line, int offset)
{
	char		buff[BUFFER_SIZE];
	char		*ref_data;
	int			read_size;

	ref_data = *data + offset;
	while (ref_data && *ref_data)
	{
		if (*ref_data == '\n')
			return (cut_string(data, line, offset, 0));
		offset++;
		ref_data++;
	}
	if ((read_size = read(fd, buff, BUFFER_SIZE)) < 0)
	{
		gnl_set_data(data, NULL);
		return (-1);
	}
	if (!read_size)
	{
		return (-1 < cut_string(data, line, offset + read_size, 1) ? 0 : -1);
	}
	if (!(gnl_set_data(data, ft_strnncat(*data, buff, offset, read_size))))
		return (-1);
	return (dispose_string(fd, data, line, offset));
}
