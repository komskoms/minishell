/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:46:23 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/05/09 06:04:56 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_length_based_cdigit(unsigned char num, int base)
{
	int				length;
	unsigned char	us_base;

	length = 1;
	us_base = (unsigned char)base;
	while (us_base - 1 < num)
	{
		++length;
		num /= us_base;
	}
	return (length);
}

char				*ft_ctoa_base(unsigned char num, int base)
{
	char			*ctoa;
	int				length;

	if (16 < base || base < 1)
	{
		return (NULL);
	}
	length = ft_length_based_cdigit(num, base);
	if (!(ctoa = (char *)malloc(length + 1)))
	{
		return (NULL);
	}
	ctoa[length] = 0;
	while (length--)
	{
		ctoa[length] = "0123456789abcdef"[num % base];
		num /= base;
	}
	return (ctoa);
}

int					ft_length_cdigit(char num)
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

char				*ft_ctoa_only_digit(char num)
{
	char			*ctoa;
	int				length;
	int				temp;

	length = ft_length_cdigit(num);
	temp = (num < 0) ? -num : num;
	if (!(ctoa = (char *)malloc(length + 1)))
	{
		return (NULL);
	}
	ctoa[length] = 0;
	while (length--)
	{
		ctoa[length] = "0123456789abcdef"[temp % 10];
		temp /= 10;
	}
	return (ctoa);
}
