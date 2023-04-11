/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:15:41 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/05/30 16:27:26 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list					*pop_list(t_list **list)
{
	t_list				*pop;

	pop = *list;
	*list = (*list)->next;
	pop->next = NULL;
	return (pop);
}

t_list					*look_list(t_list *list, unsigned int offset)
{
	while (offset && list)
	{
		offset--;
		list = list->next;
	}
	if (offset)
		return (NULL);
	return (list);
}
