/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:15:09 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/01/02 02:49:43 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*d;
	char	*s;
	char	cc;

	d = dst;
	s = (char *)src;
	cc = (char)c;
	if (d == s)
		return (dst);
	while (n-- && (*d = *s++))
	{
		if (*d == cc)
			return (++d);
		++d;
	}
	return (0);
}
