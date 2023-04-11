/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wheel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 00:38:53 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/05/05 10:39:03 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_wheel				*ft_new_wheel(void *content)
{
	t_wheel			*wheel;

	if (!content)
		return (NULL);
	wheel = (t_wheel *)malloc(sizeof(t_wheel));
	if (!wheel)
		return (NULL);
	wheel->content = content;
	wheel->next = wheel;
	wheel->prev = wheel;
	return (wheel);
}

void				*ft_addlast_wheel(t_wheel **source, t_wheel *element)
{
	if (!element)
		return (NULL);
	if (!source || !*source)
	{
		*source = element;
		return (*source);
	}
	element->next = *source;
	element->prev = (*source)->prev;
	(*source)->prev->next = element;
	(*source)->prev = element;
	return (*source);
}

void				*ft_addfront_wheel(t_wheel **source, t_wheel *element)
{
	if (!element)
		return (NULL);
	if (!source || !*source)
	{
		*source = element;
		return (*source);
	}
	ft_addlast_wheel(source, element);
	*source = (*source)->prev;
	return (*source);
}

void				ft_drop_wheel(t_wheel **wheel, void (*del)(void *))
{
	t_wheel			*start;
	t_wheel			*curr;
	t_wheel			*next;

	if (!wheel || !*wheel)
		return ;
	start = NULL;
	curr = *wheel;
	while (start != curr)
	{
		next = curr->next;
		if (!start)
			start = curr;
		if (del)
			del(curr->content);
		free(curr);
		curr = next;
	}
	*wheel = NULL;
}

ssize_t				ft_wheel_length(t_wheel *source)
{
	t_wheel			*start;
	ssize_t			length;

	length = 0;
	start = NULL;
	while (source != start)
	{
		if (!start)
			start = source;
		++length;
		source = source->next;
	}
	return (length);
}
