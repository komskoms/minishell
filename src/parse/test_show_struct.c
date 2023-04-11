/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_show_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:06:04 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/09 10:42:22 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void					test_show_order(t_mshl *parse)
{
	t_dlist				*local;

	local = parse->tokens;
	printf("\n		### parsed result :\n");
	while (local)
	{
		if (local->content)
		{
			test_show_dlist_wrap((t_dlist *)local->content, "order");
			printf("----------------------------------------------\n");
		}
		local = local->next;
	}
	printf("\e[0m\n");
}

void					test_show_dlist_wrap(t_dlist *list, char *title)
{
	t_wrap				*wrap;

	printf("		### show [\e[1;34m%s\e[0m] list :\n", title);
	while (list)
	{
		wrap = (t_wrap *)list->content;
		printf("		");
		printf("\e[0;33m-->\e[1;31m");
		printf("[%s]:[%s]\n", (char *)wrap->type, (char *)wrap->content);
		list = list->next;
	}
	printf("\e[0m\n");
}

void					test_show_darray(char **darray, char *title)
{
	int					index;

	index = 0;
	printf("		### show [\e[1;34m%s\e[0m] darray :\n", title);
	if (!darray)
	{
		printf("\e[0m\n\n");
		return ;
	}
	while (darray[index])
	{
		printf("		\e[0;33m-->\e[1;31m%s\n", darray[index]);
		index++;
	}
	printf("		\e[0;33m-->\e[1;31m%s\e[0m\n\n", darray[index]);
}

void					test_show_dlist(t_dlist *list, char *title)
{
	printf("		### show [\e[1;34m%s\e[0m] list :\n", title);
	while (list)
	{
		printf("		");
		printf("\e[0;33m(%p)-->", list->content);
		printf("\e[1;31m(%s)\n", (char *)list->content);
		list = list->next;
	}
	printf("\e[0m\n");
}

void					test_show_hashmap(t_hashmap *hashmap, char *title)
{
	int					index;
	t_dlist				*head;
	t_pair				*pair;

	index = 0;
	printf("		### show [\e[1;34m%s\e[0m] hash :\n", title);
	while (index < HASH_SIZE)
	{
		printf("		hash[%2d]: ", index);
		head = hashmap->data[index];
		while (head)
		{
			pair = (t_pair *)head->content;
			printf("\e[0;33m-->\e[1;31m");
			printf("[%s=%s] ", (char *)pair->key, (char *)pair->val);
			head = head->next;
		}
		printf("\e[0m\n");
		index++;
	}
	printf("\e[0m\n\n");
}
