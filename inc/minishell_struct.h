/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:54:22 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/04 21:10:24 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

# include "libft.h"

typedef struct			s_wrap
{
	char				*type;
	char				*content;
}						t_wrap;

typedef struct			s_proc
{
	char				**envp;
	char				**argv;
	char				*path;
	int					is_builtin;
	int					redir[2];
	int					pipe_stat;
	int					pipe[2];
	int					fd_backup[3];
	t_list				*children;
	int					last_status;
	int					last_exitcode;
}						t_proc;

typedef struct			s_mshl
{
	struct s_hashmap	*cmd_hashmap;
	struct s_hashmap	*var_hashmap;
	struct s_hashmap	*env_hashmap;
	void				*builtin[7];
	char				*line;
	struct s_dlist		*tokens;
	t_proc				proc;
	struct s_dlist		*history;
	int					history_size;
	int					error_code;
}						t_mshl;

typedef int				(*t_builtin)(t_mshl *mshl, char **cmd);

#endif
