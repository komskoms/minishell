/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:21:34 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/05/05 11:39:07 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		unit_count(const char *s, char c)
{
	int			cnt;
	int			flag;

	cnt = 0;
	flag = 1;
	while (*s)
	{
		if (flag && (*s != c) && (++cnt))
			flag = 0;
		flag = (*s == c);
		++s;
	}
	return (cnt);
}

static int		element_length(const char *s, char c)
{
	int			length;

	length = 0;
	while (*s)
	{
		if (*s != c)
			++length;
		if (*s == c)
			return (length);
		++s;
	}
	return (length);
}

static void		split_free(char **rst, int count)
{
	while (count--)
		free(rst[count]);
	free(rst);
}

static int		put_data(char **rst, const char *s, char c, int limit)
{
	int			length;
	int			count;
	int			idx;

	count = 0;
	while (limit)
	{
		if ((length = element_length(s, c)) && limit--)
		{
			idx = 0;
			if (!(rst[count] = (char *)malloc(length + 1)))
			{
				split_free(rst, count);
				return (0);
			}
			while (length-- && (rst[count][idx] = s[idx]))
				++idx;
			s += idx;
			rst[count][idx] = 0;
			++count;
		}
		else
			++s;
	}
	return (1);
}

char			**ft_split(char const *s, char c)
{
	char		**rst;
	int			length;

	if (!s)
		return (NULL);
	length = unit_count(s, c);
	if (!(rst = (char **)malloc(sizeof(char *) * (length + 1))))
		return (NULL);
	rst[length] = 0;
	if (!(put_data(rst, s, c, length)))
		return (NULL);
	return (rst);
}
