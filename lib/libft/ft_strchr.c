/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:17:37 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/02/15 20:23:29 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s - c == 0)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

int		ft_strchr_index(const char *s, int c)
{
	int	index;

	index = 0;
	while (*s)
	{
		if (*s - c == 0)
			return (index);
		s++;
		index++;
	}
	return ((c == 0) ? index : -1);
}
