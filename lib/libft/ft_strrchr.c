/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:18:14 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/01/22 14:22:29 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*tmp;
	char		*match_address;
	char		*last_address;

	tmp = s;
	last_address = 0;
	if (c == 0)
		return (char *)(s + ft_strlen(s));
	while ((match_address = ft_strchr(tmp, c)))
	{
		last_address = match_address;
		tmp = ++match_address;
	}
	return (last_address);
}
