/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:29:19 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/05/28 17:15:07 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*init(void **request, size_t size)
{
	*request = (void *)malloc(size);
	if (*request)
		ft_memset(*request, 0, size);
	return (*request);
}

void					**init3(void ***request, size_t size)
{
	*request = (void **)malloc(size);
	if (*request)
		ft_memset(*request, 0, size);
	return (*request);
}
