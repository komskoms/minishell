/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 23:41:10 by jihoon            #+#    #+#             */
/*   Updated: 2021/05/30 23:41:11 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

static void	close_fds(int fds[], int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (fds[i] != -1)
			close(fds[i]);
		i++;
	}
}

int			std_fd_backup(t_mshl *mshl)
{
	mshl->proc.fd_backup[0] = dup(0);
	mshl->proc.fd_backup[1] = dup(1);
	mshl->proc.fd_backup[2] = dup(2);
	if (mshl->proc.fd_backup[0] == -1
		|| mshl->proc.fd_backup[1] == -1
		|| mshl->proc.fd_backup[2] == -1)
	{
		close_fds(mshl->proc.fd_backup, 3);
		return (0);
	}
	return (1);
}

void		std_fd_restore(t_mshl *mshl)
{
	dup2(mshl->proc.fd_backup[0], 0);
	dup2(mshl->proc.fd_backup[1], 1);
	dup2(mshl->proc.fd_backup[2], 2);
}

int			redir_apply(t_mshl *mshl)
{
	if (mshl->proc.redir[0] != -1)
	{
		if (dup2(mshl->proc.redir[0], 0) == -1)
			return (0);
	}
	if (mshl->proc.redir[1] != -1)
	{
		if (dup2(mshl->proc.redir[1], 1) == -1)
			return (0);
	}
	return (1);
}

int			redir_to_file(t_mshl *mshl, t_dlist *token_grp)
{
	int		fd;

	if (is_token_content(token_grp, ">>"))
		fd = open(get_token_content(token_grp->next),
			O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	else if (is_token_content(token_grp, ">"))
		fd = open(get_token_content(token_grp->next),
			O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	else if (is_token_content(token_grp, "<"))
		fd = open(get_token_content(token_grp->next), O_RDONLY);
	else
		return (int_set_error_code(133, 0));
	if (fd == -1)
		return (0);
	if (is_token_content(token_grp, "<"))
		mshl->proc.redir[0] = fd;
	else
		mshl->proc.redir[1] = fd;
	return (1);
}
