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

t_dlist	*create_token(char *type, char *content)
{
	t_dlist		*token;
	t_wrap		*tk;

	token = malloc(sizeof(t_dlist));
	token->content = malloc(sizeof(t_wrap));
	token->prev = 0;
	token->next = 0;
	if (!token || !token->content)
		return (0);
	tk = token->content;
	tk->type = ft_strdup(type);
	tk->content = ft_strdup(content);
	return (token);
}

t_dlist	*add_to_last_token(t_dlist **tok_head, char *type, char *content)
{
	t_dlist		*token;
	t_dlist		*token_head;

	token_head = *tok_head;
	token = create_token(type, content);
	if (!token)
		return (0);
	if (!token_head)
	{
		*tok_head = token;
		return (token);
	}
	while (token_head->next)
		token_head = token_head->next;
	token_head->next = token;
	token->prev = token_head;
	return (token);
}

int		is_token_type(t_dlist *token, char *type)
{
	char	*tok;
	size_t	len;

	tok = get_token_type(token);
	len = ft_strlen(tok);
	if (len < ft_strlen(type))
		len = ft_strlen(type);
	return (ft_strncmp(tok, type, len) == 0);
}

int		is_token_content(t_dlist *token, char *content)
{
	char	*tok;
	size_t	len;

	tok = get_token_content(token);
	len = ft_strlen(tok);
	if (len < ft_strlen(content))
		len = ft_strlen(content);
	return (ft_strncmp(tok, content, len) == 0);
}

int		count_token_match_type(t_dlist *tokens, char *type)
{
	int		num;

	num = 0;
	while (tokens)
	{
		if (is_token_type(tokens, type))
			num++;
		tokens = tokens->next;
	}
	return (num);
}
