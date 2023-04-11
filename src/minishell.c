/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:18:08 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/08 17:12:06 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_struct.h"
#include <signal.h>

int						variables_init(t_mshl *mshl, char **envp)
{
	signal_ignores();
	ft_memset(mshl, 0, sizeof(t_mshl));
	mshl->proc.redir[0] = -1;
	mshl->proc.redir[1] = -1;
	mshl->proc.pipe[0] = -1;
	mshl->proc.pipe[1] = -1;
	if (!mshl->env_hashmap && !darray_to_hashmap(&mshl->env_hashmap, envp))
		return (0);
	if (!mshl->var_hashmap && !init_hashmap(&mshl->var_hashmap))
		return (0);
	if (!mshl->cmd_hashmap && !build_cmd_set(mshl))
		return (0);
	std_fd_backup(mshl);
	return (1);
}

int						process_by_token(t_mshl *mshl)
{
	t_dlist		*token_grp;

	if (!mshl->tokens)
		return (0);
	token_grp = mshl->tokens;
	while (token_grp)
	{
		if (!exec_by_group(mshl, token_grp->content))
			return (0);
		token_grp = token_grp->next;
		proc_post_manage(mshl);
	}
	return (1);
}

int						minishell_loop(t_mshl *mshl)
{
	int			line_stat;

	while (1)
	{
		show_prompt();
		line_stat = prompt_handler(mshl);
		if (line_stat > -1 && parse(mshl))
			process_by_token(mshl);
		dispose_error();
		drop_order(mshl);
	}
	return (1);
}
