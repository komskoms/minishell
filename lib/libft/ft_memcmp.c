/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:16:48 by kyuhkim           #+#    #+#             */
/*   Updated: 2020/12/26 14:14:57 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	limit;
	char	*src1;
	char	*src2;

	limit = 0;
	src1 = (char *)s1;
	src2 = (char *)s2;
	if (!n)
		return (0);
	while (limit < n)
	{
		if (*src1 != *src2)
		{
			return ((unsigned char)*src1 - (unsigned char)*src2);
		}
		++limit;
		++src1;
		++src2;
	}
	return (0);
}
