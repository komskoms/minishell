/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_executor01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 17:03:33 by jihoon            #+#    #+#             */
/*   Updated: 2021/06/11 17:03:34 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <dirent.h>

static int	find_this_dir(char *cmd, DIR *dirp)
{
	struct dirent	*direntry;

	while (1)
	{
		direntry = readdir(dirp);
		if (!direntry)
			break ;
		if (ft_strncmp(direntry->d_name, cmd, ft_strlen(cmd) + 1) == 0)
			return (1);
	}
	return (0);
}

static int	search_matching_cmd(t_mshl *mshl, char **dir_lst)
{
	DIR		*dirp;
	char	*tmp;
	int		i;

	i = 0;
	while (dir_lst[i])
	{
		dirp = opendir(dir_lst[i]);
		if (find_this_dir(mshl->proc.argv[0], dirp))
		{
			free(mshl->proc.path);
			tmp = ft_strjoin(dir_lst[i], "/");
			mshl->proc.path = ft_strjoin(tmp, mshl->proc.argv[0]);
			free(tmp);
			closedir(dirp);
			return (1);
		}
		closedir(dirp);
		i++;
	}
	return (0);
}

static int	find_from_envpath(t_mshl *mshl)
{
	char		**dirs;
	t_dlist		*tmp;
	int			ret;

	tmp = hashmap_pick(mshl->env_hashmap, "PATH");
	if (!tmp)
		return (0);
	dirs = ft_split(((t_pair *)tmp->content)->val, ':');
	ret = search_matching_cmd(mshl, dirs);
	drop_darray(&dirs);
	return (ret);
}

int			set_path(t_mshl *mshl)
{
	int		idx;
	int		i;

	mshl->proc.path = ft_strdup(mshl->proc.argv[0]);
	idx = -1;
	i = 0;
	while (mshl->proc.argv[0][i])
	{
		if (mshl->proc.argv[0][i] == '/')
			idx = i;
		i++;
	}
	if (++idx)
	{
		i = ft_strlen(mshl->proc.argv[0]) - idx + 1;
		ft_memmove(mshl->proc.argv[0], mshl->proc.argv[0] + idx, i);
		return (3);
	}
	else if (is_builtin(mshl, mshl->proc.path))
		return (1);
	else if (find_from_envpath(mshl))
		return (2);
	proc_argv_clear(mshl);
	mshl->proc.last_exitcode = 127;
	return (int_set_error_code(146, 0));
}
