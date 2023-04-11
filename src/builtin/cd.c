/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:09:45 by jihoon            #+#    #+#             */
/*   Updated: 2021/06/08 12:20:16 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		*get_pwd(t_pair **pwd, t_hashmap *hashmap, char *pwd_key)
{
	t_dlist		*pwd_pack;
	char		str[1024];
	size_t		key_length;
	t_pair		*pair;

	key_length = ft_strlen(pwd_key);
	pwd_pack = hashmap_pick(hashmap, pwd_key);
	if (!pwd_pack)
	{
		*pwd = NULL;
		ft_strlcpy(str, pwd_key, key_length + 1);
		str[key_length] = '=';
		getcwd(&(str[key_length + 1]), 1024 - key_length - 1);
		pair = NULL;
		if (!replace((void **)&pair, new_pair(str)))
			return (set_error_code(135));
		hashmap_update(hashmap, pair);
		pwd_pack = hashmap_pick(hashmap, pwd_key);
	}
	*pwd = (t_pair *)pwd_pack->content;
	return (*pwd);
}

static void		*env_update(t_mshl *mshl)
{
	t_pair		*cur_pair;
	t_pair		*old_pair;
	void		*backup;

	if (!get_pwd(&cur_pair, mshl->env_hashmap, "PWD") ||
		!get_pwd(&old_pair, mshl->env_hashmap, "OLDPWD"))
		return (NULL);
	backup = old_pair->val;
	old_pair->val = cur_pair->val;
	cur_pair->val = NULL;
	if (!replace((void **)&cur_pair->val, getcwd(0, 0)))
	{
		cur_pair->val = old_pair->val;
		old_pair->val = backup;
		return (set_error_code(135));
	}
	if (backup)
		free(backup);
	return (mshl);
}

static int		rollback(t_mshl *mshl, int error_code)
{
	t_pair		*cur_pair;

	if (!get_pwd(&cur_pair, mshl->env_hashmap, "PWD"))
		return (0);
	chdir((const char *)cur_pair->val);
	return (int_set_error_code(error_code, 1));
}

static char		*get_home(t_mshl *mshl)
{
	t_dlist		*home_group;
	char		*home;

	home_group = hashmap_pick(mshl->env_hashmap, "HOME");
	if (!home_group)
		return (NULL);
	home = ((t_pair *)home_group->content)->val;
	return (home);
}

int				builtin_cd(t_mshl *mshl, char **argv)
{
	int			argc;
	const char	*dir;

	argc = 0;
	while (argv[argc])
		argc++;
	if (!argc)
		return (int_set_error_code(138, 1));
	if (argc == 1 || (1 < argc && *argv[1] == '~') || !*argv[1])
	{
		dir = get_home(mshl);
		if (!dir)
			return (rollback(mshl, 141));
		if (chdir(dir) < 0)
			return (rollback(mshl, 139));
		if (1 < argc && *(argv[1] + 1) && chdir(argv[1] + 2) < 0)
			return (rollback(mshl, 139));
	}
	else if (chdir(argv[1]) == -1)
		return (rollback(mshl, 139));
	if (!env_update(mshl))
		return (rollback(mshl, 140));
	return (0);
}
