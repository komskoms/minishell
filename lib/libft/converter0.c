/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:20:23 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/05/30 16:18:40 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*dlist_to_darray(char **darray, t_dlist *dlist)
{
	t_dlist				*head;
	char				*new;
	int					index;

	if (!dlist || !darray)
		return (NULL);
	head = dlist;
	index = 0;
	while (head)
	{
		if (head->content)
		{
			new = pair_to_str((t_pair *)head->content);
			if (!new)
				return (NULL);
			darray[index] = new;
			index++;
		}
		head = head->next;
	}
	return (*darray);
}

char					**hashmap_to_darray(char ***darray, t_hashmap *hashmap)
{
	int					index;
	int					offset;

	if (!hashmap || !darray)
		return (NULL);
	if (!init3((void ***)darray, sizeof(char *) * (hashmap->count + 1)))
		return (NULL);
	index = 0;
	offset = 0;
	while (index < HASH_SIZE)
	{
		if (hashmap->data[index] &&
				!dlist_to_darray(&((*darray)[offset]), hashmap->data[index]))
		{
			drop_darray(darray);
			return (NULL);
		}
		offset = darray_element_count(*darray);
		index++;
	}
	return (*darray);
}

t_hashmap				*darray_to_hashmap(t_hashmap **hashmap, char **darray)
{
	unsigned int		index;

	if (!darray || !init_hashmap(hashmap))
		return (NULL);
	index = 0;
	while (darray[index])
	{
		if (!hashmap_update(*hashmap, new_pair(darray[index])))
		{
			hashmap_clear(hashmap);
			return (NULL);
		}
		index++;
	}
	return (*hashmap);
}
