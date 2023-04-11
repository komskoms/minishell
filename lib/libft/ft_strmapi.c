/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:04:06 by kyuhkim           #+#    #+#             */
/*   Updated: 2020/12/30 21:41:07 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*rst;
	char			*tmp;
	size_t			len;
	unsigned int	idx;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(rst = (char *)malloc(len + 1)))
		return (NULL);
	tmp = rst;
	idx = 0;
	if (f && *f)
	{
		while (len--)
		{
			*rst = f(idx++, (char)*s);
			++s;
			if (!*rst++)
				break ;
		}
	}
	*rst = 0;
	return (tmp);
}
