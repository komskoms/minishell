/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 14:12:15 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/02/21 16:49:35 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long			ft_llabs(long long n)
{
	return (n < 0) ? -n : n;
}

int					ft_length_lldigit(long long num)
{
	int					length;

	length = 1;
	num = ft_llabs(num / 10);
	while (0 < num)
	{
		num /= 10;
		++length;
	}
	return (length);
}

char				*ft_lltoa_only_digit(long long n)
{
	char			*rst;
	int				length;

	length = ft_length_lldigit(n);
	if (!(rst = (char *)malloc(length + 1)))
		return (NULL);
	rst[length] = 0;
	while (length--)
	{
		*(rst + length) = ft_abs((n % 10)) + '0';
		n /= 10;
		n = ft_llabs(n);
	}
	return (rst);
}

char				*ft_lltoa(long long n)
{
	char			*rst;
	int				is_minus;
	int				length;

	length = ft_length_lldigit(n);
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
		n = ft_llabs(n);
	}
	return (rst - is_minus);
}
