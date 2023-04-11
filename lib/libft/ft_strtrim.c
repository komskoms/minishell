/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:03:18 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/01/21 20:27:40 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*first;
	char	*last;
	char	*rst;
	char	*tmp;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	first = (char *)s1;
	last = (char *)s1 + len - 1;
	while (first <= last && ft_strchr(set, *first))
		first++;
	while (first <= last && ft_strchr(set, *last))
		last--;
	if (!(rst = (char *)malloc(last - first + 2)))
		return (NULL);
	tmp = rst;
	while (first <= last)
		*rst++ = *first++;
	*rst = 0;
	return (tmp);
}
