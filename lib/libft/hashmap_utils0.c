/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_utils0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:48:00 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/01 15:01:33 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*pair_to_str(t_pair *pair)
{
	char				*str;
	size_t				key_length;
	size_t				val_length;

	if (!pair)
		return (NULL);
	key_length = ft_strlen(pair->key);
	val_length = ft_strlen(pair->val);
	if (init((void **)&str, key_length + val_length + 2))
	{
		ft_strlcat(str, pair->key, key_length + 1);
		ft_strlcat(str, "=", key_length + 2);
		ft_strlcat(str, pair->val, key_length + val_length + 2);
	}
	return (str);
}

char					*pair_element(int name_code, void *data)
{
	t_pair				*pair;

	if (!data)
		return (NULL);
	pair = (t_pair *)data;
	if (name_code)
		return ((char *)pair->val);
	return ((char *)pair->key);
}

t_hashmap				*init_hashmap(t_hashmap **out)
{
	if (!init((void **)out, sizeof(t_hashmap)))
		return (*out);
	if (!init3((void ***)&(*out)->data, sizeof(t_dlist *) * HASH_SIZE))
	{
		free(*out);
		*out = NULL;
	}
	(*out)->count = 0;
	return (*out);
}

t_pair					*new_pair(char *str)
{
	t_pair				*new;
	char				*strchr;
	size_t				strlen;
	size_t				key_length;

	strlen = ft_strlen(str);
	strchr = ft_strchr(str, '=');
	if (strchr == str)
		return (NULL);
	key_length = strchr - str;
	if (!strchr)
		key_length = ft_strlen(str);
	if (!init((void **)&new, sizeof(t_pair)) ||
		!replace((void **)&new->key, ft_substr(str, 0, key_length)) ||
		!replace((void **)&new->val, ft_substr(str, ++key_length, strlen)))
	{
		pair_clear(new);
		return (NULL);
	}
	new->key_length = key_length - 1;
	return (new);
}

unsigned int			conv_hash(char *str)
{
	unsigned int		hash;

	hash = 0;
	while (*str)
		hash = (hash << 4) | *str++;
	return (hash % HASH_SIZE);
}
