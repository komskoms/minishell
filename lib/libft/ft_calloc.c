/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:23:43 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/02/11 08:54:42 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		length;
	char	*mem;

	length = count * size;
	if (!(mem = (char *)malloc(length)))
		return (NULL);
	while (length--)
		*mem++ = 0;
	return (mem - (count * size));
}
