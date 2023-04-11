/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 22:11:11 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/02/21 15:40:57 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_length_digit(int num)
{
	int				length;
	long long		temp;

	length = 1;
	temp = (long long)num;
	if (temp < 0)
	{
		temp = -temp;
	}
	while (9 < temp)
	{
		temp /= 10;
		++length;
	}
	return (length);
}

char				*ft_itoa_only_digit(int n)
{
	char			*rst;
	long long		tmp;
	int				length;

	length = ft_length_digit(n);
	tmp = (long long)n * ((n < 0) ? -1 : 1);
	if (!(rst = (char *)malloc(length + 1)))
		return (NULL);
	rst[length] = 0;
	while (length--)
	{
		*(rst + length) = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (rst);
}

char				*ft_itoa(int n)
{
	char			*rst;
	int				is_minus;
	int				length;
	long long		tmp;

	length = ft_length_digit(n);
	is_minus = (n < 0) ? 1 : 0;
	tmp = (long long)n * ((is_minus) ? -1 : 1);
	if (!(rst = (char *)malloc(length + is_minus + 1)))
		return (NULL);
	*(rst + length + is_minus) = 0;
	if (is_minus)
		*rst++ = '-';
	while (length--)
	{
		*(rst + length) = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (rst - is_minus);
}
