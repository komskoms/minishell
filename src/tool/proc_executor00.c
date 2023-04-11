/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:04:16 by jihokim           #+#    #+#             */
/*   Updated: 2021/06/06 16:58:08 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>
#include <sys/wait.h>

static void	pipe_redir_set(t_mshl *mshl)
{
	if (mshl->proc.pipe_stat)
	{
		if (mshl->proc.pipe_stat != 3)
		{
			if (dup2(mshl->proc.pipe[1], 1) == -1)
			{
				ft_putstr_fd(
					"minishell: child pipe connection failure\n", 2);
				exit(1);
			}
		}
		close(mshl->proc.pipe[0]);
	}
	if (!redir_apply(mshl))
	{
		ft_putstr_fd("minishell: child redirection failure\n", 2);
		exit(1);
	}
}

pid_t		new_proc(t_mshl *mshl)
{
	pid_t		pid;

	pid = fork();
	if (pid == 0)
	{
		signal_defaults();
		pipe_redir_set(mshl);
		return (execve(mshl->proc.path, mshl->proc.argv, mshl->proc.envp));
	}
	return (pid);
}

static void	post_exec_routine(t_mshl *mshl, t_dlist **cmd_lst, pid_t pid)
{
	void	*temp;

	temp = 0;
	if (pid)
		ft_lstadd_back(&mshl->proc.children, ft_lstnew(temp + pid));
	if (mshl->proc.redir[0] != -1)
	{
		close(mshl->proc.redir[0]);
		mshl->proc.redir[0] = -1;
	}
	if (mshl->proc.redir[1] != -1)
	{
		close(mshl->proc.redir[1]);
		mshl->proc.redir[1] = -1;
	}
	proc_argv_clear(mshl);
	dlist_clear(cmd_lst, 0);
}

int			exec_proc_argv(t_mshl *mshl, t_dlist **cmd_lst)
{
	pid_t		child;

	child = 0;
	mshl->proc.argv = token_to_argv(*cmd_lst);
	hashmap_to_darray(&mshl->proc.envp, mshl->env_hashmap);
	if (!mshl->proc.argv || !set_path(mshl))
	{
		dlist_clear(cmd_lst, 0);
		return (0);
	}
	if (is_builtin(mshl, mshl->proc.path))
		proc_builtin(mshl);
	else
	{
		mshl->proc.is_builtin = 0;
		child = new_proc(mshl);
		if (child == -1)
		{
			ft_putstr_fd("minishell: command execution failure\n", 2);
			exit(127);
		}
	}
	post_exec_routine(mshl, cmd_lst, child);
	return (1);
}
