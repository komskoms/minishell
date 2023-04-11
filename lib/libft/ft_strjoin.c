/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:02:40 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/02/16 04:02:09 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rst;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	if (!(rst = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	tmp = rst;
	while (*s1)
		*rst++ = *s1++;
	while (*s2)
		*rst++ = *s2++;
	*rst = 0;
	return (tmp);
}
