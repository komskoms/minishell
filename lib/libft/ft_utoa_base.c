/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 08:28:54 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/02/19 07:54:00 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_length_based_udigit(unsigned int num,
											unsigned int base)
{
	int				length;

	length = 1;
	while (base - 1 < num)
	{
		num /= base;
		++length;
	}
	return (length);
}

static char			*ft_utoa_base_put(char *dest, unsigned int num,
											unsigned int base)
{
	char			mod;

	mod = "0123456789abcdef"[num % base];
	if (base - 1 < num)
	{
		num /= base;
		dest = ft_utoa_base_put(dest, num, base);
	}
	*dest++ = mod;
	return (dest);
}

char				*ft_utoa_base(unsigned int num, unsigned int base)
{
	char			*utoa;
	int				length;

	if (base < 1)
		return (NULL);
	length = ft_length_based_udigit(num, base);
	if (!(utoa = (char *)malloc(length + 1)))
	{
		return (NULL);
	}
	ft_utoa_base_put(utoa, num, base);
	utoa[length] = 0;
	return (utoa);
}
