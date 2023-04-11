/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 14:12:15 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/05/09 06:05:28 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long				ft_labs(long n)
{
	return (n < 0) ? -n : n;
}

int					ft_length_ldigit(long num)
{
	int					length;

	length = 1;
	num = ft_labs(num / 10);
	while (0 < num)
	{
		num /= 10;
		++length;
	}
	return (length);
}

char				*ft_ltoa_only_digit(long n)
{
	char			*rst;
	int				length;

	length = ft_length_ldigit(n);
	if (!(rst = (char *)malloc(length + 1)))
		return (NULL);
	rst[length] = 0;
	while (length--)
	{
		*(rst + length) = ft_abs((n % 10)) + '0';
		n /= 10;
		n = ft_labs(n);
	}
	return (rst);
}

char				*ft_ltoa(long n)
{
	char			*rst;
	int				is_minus;
	int				length;

	length = ft_length_ldigit(n);
	is_minus = (n < 0) ? 1 : 0;
	if (!(rst = (char *)malloc(length + is_minus + 1)))
		return (NULL);
	*(rst + length + is_minus) = 0;
	if (is_minus)
		*rst++ = '-';
	while (length--)
	{
		*(rst + length) = ft_abs((n % 10)) + '0';
		n /= 10;
		n = ft_labs(n);
	}
	return (rst - is_minus);
}

char				*ft_lutoa_base(unsigned long long num, int base)
{
	char				*itoa;
	int					length;
	unsigned long long	ull_base;
	unsigned long long	temp;

	if (16 < base || base < 1)
		return (NULL);
	length = 1;
	temp = num;
	ull_base = (unsigned long long)base;
	while (ull_base - 1 < temp)
	{
		++length;
		temp /= ull_base;
	}
	length = ft_length_based_lludigit(num, base);
	if (!(itoa = (char *)malloc(length + 1)))
		return (NULL);
	itoa[length] = 0;
	while (length--)
	{
		itoa[length] = "0123456789abcdef"[num % base];
		num /= base;
	}
	return (itoa);
}
