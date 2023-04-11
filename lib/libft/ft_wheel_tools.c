/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wheel_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 04:15:45 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/05/05 09:15:46 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_wheel				*ft_join_wheel(t_wheel *source, t_wheel *append)
{
	t_wheel *temp;

	if (!source)
	{
		return (append);
	}
	if (!append)
	{
		return (source);
	}
	temp = source->prev;
	source->prev = append->prev;
	append->prev = temp;
	append->prev->next = append;
	source->prev->next = source;
	return (source);
}

void				ft_del_current_wheel(t_wheel **source)
{
	t_wheel			*target;

	target = ft_pop_current_wheel(source);
	if (target)
	{
		free(target->content);
		free(target);
	}
}

t_wheel				*ft_pop_current_wheel(t_wheel **source)
{
	t_wheel			*target;

	if (!source || !*source)
		return (NULL);
	target = *source;
	if (target == target->next)
		*source = NULL;
	else
	{
		target->next->prev = target->prev;
		target->prev->next = target->next;
		*source = target->next;
	}
	target->next = target;
	target->prev = target;
	return (target);
}
