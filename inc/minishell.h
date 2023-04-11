/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:07:50 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/09 10:42:12 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "minishell_struct.h"

# define GROUP "\"'"
# define IGNORE "\\"
# define SLASH "/"
# define SEPERATOR ";"
# define ENV_SIGN "$"
# define SPACE "\t\v\f\r "
# define NEW_LINE "\n"
# define ASC_COMMAND "&<>|"
# define SPECIAL_PARAMETER "?"
# define MAX_HISTORY_SIZE 100
# define CUSTOM_ERROR_CODE 130
# define MS_REDIR "redir"
# define MS_PIPE "pipe"
# define MS_SEMICOLON "semicolon"
# define MS_CMD "cmd"
# define MS_FILE "file"
# define MS_ENV "env"
# define MS_IGNORE_TOKEN "ignore_token"
# define ECHO_OPTION "n"

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>

int					minishell_loop(t_mshl *mshl);
int					variables_init(t_mshl *mshl, char **envp);
void				signal_ignores(void);
void				signal_defaults(void);
/*
** bultin_func
*/
void				print_hashmap(t_hashmap *hashmap, char *prefix);
int					builtin_env(void *mshl, char **cmd);
int					builtin_echo(void *mshl, char **cmd);
int					builtin_cd(t_mshl *mshl, char **cmd);
int					builtin_pwd(t_mshl *mshl, char **cmd);
int					builtin_export(void *mshl, char **cmd);
int					builtin_unset(void *mshl, char **cmd);
int					builtin_exit(t_mshl *mshl, char **cmd);
/*
** parse_related
*/
void				dispose_error(void);
void				*set_error_code(int error_code);
int					int_set_error_code(int error_code, int response);
void				*parse(t_mshl *mshl);
void				*split_element(char **command, t_dlist **element_dlist);
void				*split_token(t_dlist *element_dlist);
void				*route_parse(t_dlist **token, t_dlist **wrap_list);
char				*syntax(t_dlist *list);
void				takeoff_decorate(char *str);
void				set_group_flag(char *quote_flag, char command);
void				del_wrap(void *content);
void				drop_order(t_mshl *parse);
void				drop_mshl(t_mshl *out);
void				*split_semicolon(t_mshl *out, t_dlist **list);
void				*is_builtin_cmd(t_mshl *mshl, char *cmd);
void				*build_cmd_set(t_mshl *mshl);
int					is_env(char *content);
int					is_key(char *content);
int					is_builtin(t_mshl *mshl, char *cmd);
int					get_key_size(char *content);
t_dlist				*get_env_var_hashmap(t_mshl *mshl, char *key);
void				*exchange_sp_param(
				char **exchange, t_mshl *mshl, char *token);
void				takeoff_all_decorate(t_mshl *mshl);
int					exchange_key_to_value(
				t_dlist *dest, t_mshl *mshl, int offset);
void				transform_env(t_dlist *list);
void				no_point_but_norm(void **cmd);
/*
** token_handling
*/
t_dlist				*create_token(char *type, char *content);
t_dlist				*add_to_last_token(
				t_dlist **tok_head, char *type, char *content);
int					is_token_type(t_dlist *token, char *type);
int					is_token_content(t_dlist *token, char *content);
char				*get_token_type(t_dlist *token);
char				*get_token_content(t_dlist *token);
char				**token_to_argv(t_dlist *tokens);
int					count_token_match_type(t_dlist *tokens, char *type);
t_dlist				**split_tokens_by_type(t_dlist *tokens_head, char *type);
void				list_tokens_clear(t_dlist **list_tokens);
int					exec_by_group(t_mshl *mshl, t_dlist *token_grp);
/*
** process_handling
*/
int					prompt_handler(t_mshl *mshl);
pid_t				new_proc(t_mshl *mshl);
int					std_fd_backup(t_mshl *mshl);
void				std_fd_restore(t_mshl *mshl);
int					redir_to_file(t_mshl *mshl, t_dlist *token_grp);
int					redir_apply(t_mshl *mshl);
int					set_path(t_mshl *mshl);
int					proc_builtin(t_mshl *mshl);
int					exec_proc_argv(t_mshl *mshl, t_dlist **cmd_lst);
int					exec_with_pipe(t_mshl *mshl, t_dlist **cmd_lst);
void				proc_argv_clear(t_mshl *mshl);
void				proc_post_manage(t_mshl *mshl);
/*
** debuging functions
*/
void				test_show_order(t_mshl *parse);
void				test_show_dlist_wrap(t_dlist *list, char *title);
void				test_show_darray(char **darray, char *title);
void				test_show_dlist(t_dlist *list, char *title);
void				test_show_hashmap(t_hashmap *hashmap, char *title);
void				print_tokens(t_dlist *token_lst);
void				print_list_tokens(t_dlist *list_tokens);
void				print_argv(char **argv);

#endif
