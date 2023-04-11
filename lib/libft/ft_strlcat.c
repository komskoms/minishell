/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:20:43 by kyuhkim           #+#    #+#             */
/*   Updated: 2020/12/31 20:41:52 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	rst;

	rst = 0;
	if (size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	while (*dst && dst)
	{
		if (0 < size)
		{
			--size;
			++rst;
		}
		++dst;
	}
	rst += ft_strlcpy(dst, src, size);
	return (rst);
}
