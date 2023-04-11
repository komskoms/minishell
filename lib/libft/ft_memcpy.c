/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:15:50 by kyuhkim           #+#    #+#             */
/*   Updated: 2020/12/30 12:03:28 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	pin;
	int		dir;

	if (dst == src)
		return (dst);
	d = dst;
	s = (char *)src;
	pin = (dst < src) ? len - 1 : 0;
	dir = (dst < src) ? 1 : -1;
	while (len--)
		*(d + dir * (pin - len)) = *(s + dir * (pin - len));
	return (dst);
}
