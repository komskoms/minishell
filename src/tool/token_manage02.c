/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:27:36 by jihoon            #+#    #+#             */
/*   Updated: 2021/05/29 17:27:53 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_token_content(t_dlist *token)
{
	return (((t_wrap *)token->content)->content);
}

char	*get_token_type(t_dlist *token)
{
	return (((t_wrap *)token->content)->type);
}

char	**token_to_argv(t_dlist *tokens)
{
	char	**new;
	int		size;
	int		i;

	size = dlist_size(tokens);
	new = ft_calloc(size + 1, sizeof(char *));
	if (!new)
		return (0);
	i = 0;
	while (i < size)
	{
		new[i] = ft_strdup(get_token_content(tokens));
		if (!new[i])
		{
			while (i--)
				free(new[i]);
			free(new);
			return (0);
		}
		tokens = tokens->next;
		i++;
	}
	return (new);
}
