/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:22:12 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/02/03 05:33:45 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (!needle || !*needle)
		return ((char *)haystack);
	while (len && *haystack)
	{
		if ((*haystack == *needle) && !(len < n_len))
		{
			if (!ft_strncmp(haystack, needle, n_len))
				return ((char *)haystack);
		}
		++haystack;
		--len;
	}
	return (NULL);
}
