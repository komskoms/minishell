/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bias.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 00:42:55 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/02/17 08:09:09 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_get_full_bit(int length)
{
	unsigned long long	full_bit;

	full_bit = 0;
	while (length--)
	{
		full_bit = (full_bit << 1) | 1;
	}
	return (full_bit);
}

t_bias				*ft_new_bias(void)
{
	t_lld			lld;
	t_bias			*bias;

	if (!(bias = (t_bias *)malloc(sizeof(t_bias))))
		return (NULL);
	lld.d = 1.5;
	bias->ll_size = 0;
	bias->real_size = 0;
	bias->unreal_size = 0;
	while (!(lld.ll & 1))
	{
		bias->unreal_size++;
		(lld.ll >>= 1);
	}
	bias->unreal_size++;
	lld.ll >>= 1;
	while ((lld.ll & 1))
	{
		bias->real_size++;
		lld.ll >>= 1;
	}
	bias->real_size++;
	bias->bias = (1 << (bias->real_size - 1)) - 1;
	bias->ll_size = bias->real_size + bias->unreal_size + 1;
	return (bias);
}
