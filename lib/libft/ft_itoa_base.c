/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:49:00 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/02/19 03:49:40 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_length_based_digit(int num, int base)
{
	long long		temp;
	int				length;

	temp = (long long)num;
	temp = (num < 0) ? -temp : temp;
	length = 1;
	while (base - 1 < temp)
	{
		temp /= base;
		length++;
	}
	return (length);
}

int					ft_abs(int num)
{
	return ((num < 0) ? -num : num);
}

static char			*ft_itoa_base_put(char *dest, int num, int base)
{
	char			mod;
	long long		temp;

	temp = (long long)num;
	temp = (num < 0) ? -temp : temp;
	if (temp < 0)
		temp = -temp;
	mod = "0123456789abcdef"[temp % base];
	if ((base - 1) < temp)
	{
		temp /= base;
		dest = ft_itoa_base_put(dest, (int)temp, base);
	}
	*dest++ = mod;
	return (dest);
}

char				*ft_itoa_base(int num, int base)
{
	char			*itoa;
	int				length;

	if (base < 1 || 16 < base)
	{
		return (NULL);
	}
	length = ft_length_based_digit(num, base);
	if (!(itoa = (char *)malloc(length + 1)))
	{
		return (NULL);
	}
	itoa[length] = 0;
	ft_itoa_base_put(itoa, num, base);
	return (itoa);
}
