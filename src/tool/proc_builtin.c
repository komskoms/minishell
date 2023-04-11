/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:28:42 by jihokim           #+#    #+#             */
/*   Updated: 2021/06/06 17:01:17 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	call_builtin(t_mshl *mshl, int code)
{
	return (((t_builtin)mshl->builtin[code])(mshl, mshl->proc.argv));
}

static int	redir_restore_builtin(t_mshl *mshl)
{
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
	if (mshl->proc.pipe_stat == 3)
	{
		dup2(mshl->proc.pipe[0], 0);
		mshl->proc.pipe_stat = 0;
	}
	return (1);
}

int			proc_builtin(t_mshl *mshl)
{
	int		builtin_code;

	mshl->proc.is_builtin = 1;
	if (mshl->proc.pipe_stat)
	{
		if (mshl->proc.pipe_stat != 3)
		{
			if (dup2(mshl->proc.pipe[1], 1) == -1)
			{
				ft_putstr_fd("minish: child pipe connection failure\n", 2);
				return (0);
			}
		}
	}
	if (!redir_apply(mshl))
		return (0);
	builtin_code = is_builtin(mshl, mshl->proc.argv[0]) - 1;
	mshl->proc.last_exitcode = call_builtin(mshl, builtin_code);
	redir_restore_builtin(mshl);
	return (1);
}
