/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_post_manage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:56:14 by jihokim           #+#    #+#             */
/*   Updated: 2021/06/06 17:00:06 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/wait.h>

void		proc_argv_clear(t_mshl *mshl)
{
	drop_darray(&mshl->proc.argv);
	drop_darray(&mshl->proc.envp);
	free(mshl->proc.path);
}

static void	exitcode_verify(t_mshl *mshl)
{
	if (mshl->proc.is_builtin)
		return ;
	mshl->proc.last_exitcode = WEXITSTATUS(mshl->proc.last_status);
	if (WIFSIGNALED(mshl->proc.last_status))
	{
		mshl->proc.last_exitcode = 128 + WTERMSIG(mshl->proc.last_status);
		write(1, "\n", 1);
	}
}

static void	wait_for_children(t_mshl *mshl)
{
	t_list		*lst;

	lst = mshl->proc.children;
	while (lst)
	{
		waitpid((long)lst->content, &mshl->proc.last_status, 0);
		lst = lst->next;
	}
	ft_lstclear(&mshl->proc.children, 0);
}

void		proc_post_manage(t_mshl *mshl)
{
	wait_for_children(mshl);
	mshl->proc.redir[0] = -1;
	mshl->proc.redir[1] = -1;
	mshl->proc.pipe_stat = 0;
	mshl->proc.pipe[0] = -1;
	mshl->proc.pipe[1] = -1;
	dup2(mshl->proc.fd_backup[0], 0);
	exitcode_verify(mshl);
	std_fd_restore(mshl);
}
