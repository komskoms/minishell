/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:04:20 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/02/21 16:37:10 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_length_based_lludigit(unsigned long long num, int base)
{
	int					length;
	unsigned long long	ull_base;

	length = 1;
	ull_base = (unsigned long long)base;
	while (ull_base - 1 < num)
	{
		++length;
		num /= ull_base;
	}
	return (length);
}

char				*ft_llutoa_base(unsigned long long num, int base)
{
	char			*itoa;
	int				length;

	if (16 < base || base < 1)
		return (NULL);
	length = ft_length_based_lludigit(num, base);
	if (!(itoa = (char *)malloc(length + 1)))
	{
		return (NULL);
	}
	itoa[length] = 0;
	while (length--)
	{
		itoa[length] = "0123456789abcdef"[num % base];
		num /= base;
	}
	return (itoa);
}
