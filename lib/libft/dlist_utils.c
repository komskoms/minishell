/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:00:42 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/09 10:26:28 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*dlist_new(void *content)
{
	t_dlist				*new;

	init((void **)&new, sizeof(t_dlist));
	if (new)
		new->content = content;
	return (new);
}

void					*dlist_add_front(t_dlist **dlist, t_dlist *new)
{
	t_dlist				*head;

	head = *dlist;
	new->next = head;
	if (head)
		head->prev = new;
	*dlist = new;
	return (new);
}

void					*dlist_add_last(t_dlist **dlist, t_dlist *new)
{
	t_dlist				*temp;

	if (!*dlist)
	{
		*dlist = new;
		return (NULL);
	}
	else
	{
		temp = *dlist;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
	return (*dlist);
}

void					dlist_clear(t_dlist **dlist, void (*del)(void *))
{
	t_dlist				*temp;

	if (!dlist)
		return ;
	while (*dlist)
	{
		temp = *dlist;
		if (del)
		{
			if (temp->content)
			{
				del(temp->content);
			}
		}
		*dlist = temp->next;
		free(temp);
	}
}

int						dlist_size(t_dlist *dlist)
{
	int					size;

	size = 0;
	while (dlist)
	{
		size++;
		dlist = dlist->next;
	}
	return (size);
}
