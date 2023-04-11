/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:20:06 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/05/08 23:48:03 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	rst;

	rst = 0;
	if (!size)
		return (ft_strlen(src));
	if (!dst && !src)
		return (rst);
	while (*src)
	{
		if (0 < size && --size && (*dst = *src))
			++dst;
		++src;
		++rst;
	}
	*dst = 0;
	return (rst);
}
