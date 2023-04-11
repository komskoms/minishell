/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_charalloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 20:46:32 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/02/16 02:24:49 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_charalloc(size_t size, char c)
{
	char		*result;

	if (!(result = (char *)malloc(size + 1)))
	{
		return (NULL);
	}
	result[size] = 0;
	ft_memset(result, c, size);
	return (result);
}
