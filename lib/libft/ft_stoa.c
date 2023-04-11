/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:46:26 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/05/09 06:05:51 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_length_based_sdigit(unsigned short num, int base)
{
	int				length;
	unsigned short	us_base;

	length = 1;
	us_base = (unsigned short)base;
	while (us_base - 1 < num)
	{
		++length;
		num /= us_base;
	}
	return (length);
}

char				*ft_stoa_base(unsigned short num, int base)
{
	char			*stoa;
	int				length;

	if (16 < base || base < 1)
	{
		return (NULL);
	}
	length = ft_length_based_sdigit(num, base);
	if (!(stoa = (char *)malloc(length + 1)))
	{
		return (NULL);
	}
	stoa[length] = 0;
	while (length--)
	{
		stoa[length] = "0123456789abcdef"[num % base];
		num /= base;
	}
	return (stoa);
}

int					ft_length_sdigit(short num)
{
	int				length;
	int				temp;

	temp = (num < 0) ? -num : num;
	length = 1;
	while (9 < temp)
	{
		temp /= 10;
		length++;
	}
	return (length);
}

char				*ft_stoa_only_digit(short num)
{
	char			*stoa;
	int				length;
	int				temp;

	length = ft_length_sdigit(num);
	temp = (num < 0) ? -num : num;
	if (!(stoa = (char *)malloc(length + 1)))
	{
		return (NULL);
	}
	stoa[length] = 0;
	while (length--)
	{
		stoa[length] = "0123456789abcdef"[temp % 10];
		temp /= 10;
	}
	return (stoa);
}
