/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:02:12 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/05/24 04:34:23 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*rst;
	char	*tmp;

	if (!s)
		return (NULL);
	while (start-- && *s)
		s++;
	s_len = ft_strlen(s);
	len = (s_len < len) ? s_len : len;
	if (!(rst = (char *)malloc(len + 1)))
		return (NULL);
	tmp = rst;
	rst[len] = 0;
	while (len-- && (*rst++ = *s++))
		;
	return (tmp);
}
