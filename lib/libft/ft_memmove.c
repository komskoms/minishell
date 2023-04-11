/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:15:50 by kyuhkim           #+#    #+#             */
/*   Updated: 2020/12/30 12:13:57 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	pin;
	int		dir;

	d = dst;
	s = (char *)src;
	if (d == s)
		return (dst);
	pin = (d < s) ? len - 1 : 0;
	dir = (d < s) ? 1 : -1;
	while (len--)
		*(d + dir * (pin - len)) = *(s + dir * (pin - len));
	return (dst);
}
