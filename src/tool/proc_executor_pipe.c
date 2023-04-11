/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:04:16 by jihokim           #+#    #+#             */
/*   Updated: 2021/05/27 19:30:25 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>
#include <sys/wait.h>

static void	pipe_stat_set(t_mshl *mshl)
{
	if (!mshl->proc.pipe_stat)
		mshl->proc.pipe_stat = 1;
	else
	{
		close(mshl->proc.pipe[0]);
		mshl->proc.pipe_stat = 2;
	}
}

static void	pipe_post_stat_set(t_mshl *mshl)
{
	if (mshl->proc.pipe_stat)
	{
		close(mshl->proc.pipe[1]);
		dup2(mshl->proc.fd_backup[1], 1);
		dup2(mshl->proc.pipe[0], 0);
	}
	mshl->proc.pipe_stat = 3;
}

int			exec_with_pipe(t_mshl *mshl, t_dlist **cmd_lst)
{
	int		new_pipe[2];

	if (pipe(new_pipe) == -1)
		return (0);
	pipe_stat_set(mshl);
	mshl->proc.pipe[0] = new_pipe[0];
	mshl->proc.pipe[1] = new_pipe[1];
	exec_proc_argv(mshl, cmd_lst);
	pipe_post_stat_set(mshl);
	return (1);
}
