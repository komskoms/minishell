/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:28:10 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/01 10:58:28 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist					*hashmap_update(t_hashmap *hashmap, t_pair *pair)
{
	t_dlist				*current;

	if (!pair || !hashmap)
		return (NULL);
	current = hashmap_pick(hashmap, pair->key);
	if (!current)
	{
		if (!init((void **)&current, sizeof(t_dlist)))
			return (NULL);
		current->content = pair;
		dlist_add_front(&hashmap->data[conv_hash(pair->key)], current);
		hashmap->count++;
	}
	else
	{
		replace((void **)&((t_pair *)current->content)->val, pair->val);
		pair->val = NULL;
		pair_clear(pair);
	}
	return (current);
}

t_dlist					*hashmap_pick(t_hashmap *hashmap, char *key)
{
	int					index;
	t_dlist				*head;
	t_pair				*curr_pair;
	size_t				key_length;

	if (!hashmap || !key)
		return (NULL);
	key_length = ft_strlen(key);
	index = conv_hash(key);
	head = hashmap->data[index];
	while (head)
	{
		curr_pair = (t_pair *)head->content;
		if (key_length == curr_pair->key_length &&
							!ft_strncmp(key, curr_pair->key, key_length + 1))
			return (head);
		head = head->next;
	}
	return (NULL);
}

t_pair					*hashmap_pop(t_hashmap *hashmap, char *key)
{
	t_dlist				*dlist;
	t_pair				*pair;
	int					tarconv_hash;

	if (!hashmap || !key)
		return (NULL);
	pair = NULL;
	dlist = (t_dlist *)hashmap_pick(hashmap, key);
	if (dlist)
	{
		tarconv_hash = conv_hash(((t_pair *)dlist->content)->key);
		if (dlist->prev)
			dlist->prev->next = dlist->next;
		else
			hashmap->data[tarconv_hash] = dlist->next;
		if (dlist->next)
			dlist->next->prev = dlist->prev;
		pair = dlist->content;
		free(dlist);
		hashmap->count--;
	}
	return (pair);
}

void					hashmap_clear(t_hashmap **hashmap)
{
	int					index;

	if (!hashmap || !*hashmap)
		return ;
	index = 0;
	while (index < HASH_SIZE)
	{
		dlist_clear(&(*hashmap)->data[index], pair_clear);
		index++;
	}
	free((*hashmap)->data);
	free(*hashmap);
	*hashmap = NULL;
}

void					pair_clear(void *pair)
{
	t_pair				*convert;

	if (pair)
	{
		convert = (t_pair *)pair;
		if (convert->key)
			free(convert->key);
		if (convert->val)
			free(convert->val);
		free(convert);
	}
}
