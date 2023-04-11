/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:24:10 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/05/25 22:03:47 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*rst;

	length = ft_strlen(s1);
	if (!(rst = (char *)malloc(length + 1)))
		return (NULL);
	ft_strlcpy(rst, s1, length + 1);
	return (rst);
}
