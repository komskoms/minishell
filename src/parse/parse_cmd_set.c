/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:31:50 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/01 15:56:25 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_struct.h"

void					*is_builtin_cmd(t_mshl *mshl, char *cmd)
{
	return (hashmap_pick(mshl->cmd_hashmap, cmd));
}

static void				build_builtin_array(t_mshl *mshl)
{
	mshl->builtin[0] = builtin_echo;
	mshl->builtin[1] = builtin_cd;
	mshl->builtin[2] = builtin_pwd;
	mshl->builtin[3] = builtin_export;
	mshl->builtin[4] = builtin_unset;
	mshl->builtin[5] = builtin_env;
	mshl->builtin[6] = builtin_exit;
}

void					*build_cmd_set(t_mshl *mshl)
{
	if (!(init_hashmap(&mshl->cmd_hashmap)))
		return (set_error_code(135));
	if (!(hashmap_update(mshl->cmd_hashmap, new_pair("echo=0"))) ||
		!(hashmap_update(mshl->cmd_hashmap, new_pair("cd=1"))) ||
		!(hashmap_update(mshl->cmd_hashmap, new_pair("pwd=2"))) ||
		!(hashmap_update(mshl->cmd_hashmap, new_pair("export=3"))) ||
		!(hashmap_update(mshl->cmd_hashmap, new_pair("unset=4"))) ||
		!(hashmap_update(mshl->cmd_hashmap, new_pair("env=5"))) ||
		!(hashmap_update(mshl->cmd_hashmap, new_pair("exit=6"))))
	{
		hashmap_clear(&mshl->cmd_hashmap);
		return (set_error_code(135));
	}
	build_builtin_array(mshl);
	return (mshl->cmd_hashmap);
}
