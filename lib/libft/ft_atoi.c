/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:23:14 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/05/06 22:24:27 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(char c)
{
	return ((9 <= c && c <= 13) || (c == 32));
}

static int		ft_isoverflowllu(int len, int dir, unsigned long long value)
{
	unsigned long long	signedll_max;

	signedll_max = -1;
	signedll_max >>= 1;
	if (19 < len)
		return (-(0 < dir));
	if (signedll_max + 1 < value && dir < 0)
		return (0);
	if (signedll_max < value && 0 < dir)
		return (-1);
	return (1);
}

static char		*ft_build_atoi_value(unsigned long long *rst, char *s, int *len)
{
	*rst = *rst * 10 + (*s - '0');
	*len = *len + 1;
	s++;
	return (s);
}

int				ft_atoi(const char *str)
{
	unsigned long long	rst;
	int					dir;
	int					a_len;
	int					is_overflow;

	a_len = 0;
	rst = 0;
	dir = 1;
	while ((ft_isspace(*str)))
		str++;
	if ((*str == '-' || *str == '+'))
	{
		if (*str == '-')
			dir = -1;
		str++;
	}
	while ((ft_isdigit(*str)))
	{
		str = ft_build_atoi_value(&rst, (char *)str, &a_len);
		if ((is_overflow = ft_isoverflowllu(a_len, dir, rst)) < 1)
			return (is_overflow);
	}
	return (int)(rst * dir);
}
