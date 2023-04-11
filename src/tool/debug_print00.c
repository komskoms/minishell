/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:06:28 by jihokim           #+#    #+#             */
/*   Updated: 2021/05/27 16:21:46 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tokens(t_dlist *token_lst)
{
	while (token_lst)
	{
		printf("		\e[0;33m-->[\e[1;34m%s\e[0;33m:\e[1;31m%s\e[0;33m]\n",
			get_token_type(token_lst), get_token_content(token_lst));
		token_lst = token_lst->next;
	}
	printf("-------------------------------------------------------------\n");
	printf("\e[0m\n");
}

void	print_list_tokens(t_dlist *list_tokens)
{
	while (list_tokens)
	{
		print_tokens(list_tokens->content);
		list_tokens = list_tokens->next;
	}
}

void	print_argv(char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
		printf("[%s]\n", argv[i++]);
}
