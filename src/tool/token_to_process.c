/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:07:28 by jihoon            #+#    #+#             */
/*   Updated: 2021/06/07 14:51:35 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h>
#include <string.h>

static int	add_cmd_dlist(t_dlist **cmd_lst, t_dlist *token)
{
	t_dlist		*new;

	new = dlist_new(token->content);
	if (!new)
		return (0);
	dlist_add_last(cmd_lst, new);
	return (1);
}

int			evmap_update(t_mshl *mshl, t_dlist *token)
{
	char		*content;
	t_pair		*add_pair;
	t_pair		*ev_pair;
	t_dlist		*ev_pack;
	t_hashmap	*hashmap;

	add_pair = NULL;
	ev_pack = NULL;
	ev_pair = NULL;
	content = (char *)((t_wrap *)token->content)->content;
	if (!replace((void **)&add_pair, new_pair(content)))
		return (int_set_error_code(135, 0));
	ev_pack = get_env_var_hashmap(mshl, (char *)add_pair->key);
	if (ev_pack)
		ev_pair = (t_pair *)ev_pack->content;
	hashmap = mshl->env_hashmap;
	if (!ev_pair)
		hashmap = mshl->var_hashmap;
	if (!hashmap_update(hashmap, add_pair))
		return (0);
	return (1);
}

static int	token_analyze(t_mshl *mshl, t_dlist **token_grp, t_dlist **cmd_lst)
{
	if (is_token_type(*token_grp, MS_CMD))
	{
		if (!add_cmd_dlist(cmd_lst, *token_grp))
			return (0);
	}
	else if (is_token_type(*token_grp, MS_REDIR))
	{
		if (!redir_to_file(mshl, *token_grp))
			return (0);
		*token_grp = (*token_grp)->next;
	}
	else if (is_token_type(*token_grp, MS_PIPE))
	{
		if (!exec_with_pipe(mshl, cmd_lst))
			return (0);
	}
	else if (is_token_type(*token_grp, MS_ENV))
	{
		if (!evmap_update(mshl, *token_grp))
			return (0);
	}
	return (1);
}

int			exec_by_group(t_mshl *mshl, t_dlist *token_grp)
{
	t_dlist		*cmd_lst;

	cmd_lst = 0;
	if (!token_grp)
		return (1);
	while (1)
	{
		if (!token_analyze(mshl, &token_grp, &cmd_lst))
			return (0);
		token_grp = token_grp->next;
		if (!token_grp)
			break ;
	}
	if (cmd_lst)
		exec_proc_argv(mshl, &cmd_lst);
	return (1);
}
