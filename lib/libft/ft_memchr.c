/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:16:22 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/01/21 20:32:14 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			limit;
	unsigned char	*tmp;
	unsigned char	uc;

	limit = 0;
	tmp = (unsigned char *)s;
	uc = (unsigned char)c;
	while (limit < n)
	{
		if (*tmp++ == uc)
			return (tmp - 1);
		++limit;
	}
	return (0);
}
