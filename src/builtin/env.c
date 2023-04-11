/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:27:03 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/04 21:26:01 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_struct.h"
#include "minishell.h"

void					print_hashmap(t_hashmap *hashmap, char *prefix)
{
	int					index;
	t_dlist				*head;
	t_pair				*pair;

	index = 0;
	while (index < HASH_SIZE)
	{
		head = hashmap->data[index];
		while (head)
		{
			pair = (t_pair *)head->content;
			if (prefix)
			{
				printf("%s", prefix);
				printf("%s=\"%s\"\n", (char *)pair->key, (char *)pair->val);
			}
			else
				printf("%s=%s\n", (char *)pair->key, (char *)pair->val);
			head = head->next;
		}
		index++;
	}
}

int						builtin_env(void *pack, char **cmd)
{
	t_mshl				*mshl;

	no_point_but_norm((void **)cmd);
	mshl = (t_mshl *)pack;
	print_hashmap(mshl->env_hashmap, NULL);
	return (0);
}
