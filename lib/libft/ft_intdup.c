/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 08:16:24 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/05/09 06:01:57 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						*ft_intdup(int value)
{
	int					*result;

	result = (int *)malloc(sizeof(int));
	if (result)
		*result = value;
	return (result);
}
