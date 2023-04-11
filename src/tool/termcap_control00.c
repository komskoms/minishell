/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap_control00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:10:25 by jihoon            #+#    #+#             */
/*   Updated: 2021/06/04 11:10:26 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcap_control.h"
#include <stdio.h>

int	init_line(char **line)
{
	if (!line)
		return (0);
	*line = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!*line)
		return (0);
	return (1);
}

int	last_procedure(char **line, int len)
{
	char	last;

	last = (*line)[len];
	(*line)[len] = '\0';
	if (last == '\n')
		return (1);
	else
		return (0);
}

int	lengthen_line(char **line, int size)
{
	char	*new;

	new = ft_calloc(size + BUFFER_SIZE, sizeof(char));
	if (!new)
		return (0);
	ft_strlcpy(new, *line, size);
	free(*line);
	*line = new;
	return (1);
}
