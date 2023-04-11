/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap_control.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:47:13 by jihokim           #+#    #+#             */
/*   Updated: 2021/06/04 15:47:20 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAP_CONTROL_H
# define TERMCAP_CONTROL_H

# include "minishell_struct.h"
# include "libft.h"
# include <termios.h>
# include <termcap.h>

# define BACKSPACE 127
# define EOF_KEY 4
# define RETURN 10
# define LEFT_ARROW 4479771
# define RIGHT_ARROW 4414235
# define UP_ARROW 4283163
# define DOWN_ARROW 4348699

# define TC_GET_CURSOR_POS "\033[6n"

# define BUFFER_SIZE 256

# include <stddef.h>
# include <stdlib.h>

typedef struct	s_tcntl
{
	struct termios	term;
	struct termios	ori_term;
	unsigned int	ch;
	char			*line_ori;
	size_t			ln_idx;
	int				his_idx;
	int				i_pos[2];
	int				c_pos[2];
	char			*env_term;
	char			*cm;
	char			*ce;
}				t_tcntl;

int				init_line(char **line);
int				last_procedure(char **line, int	len);
int				lengthen_line(char **line, int size);
char			*strdup_bybuffersize(char *str);
void			get_cursor_position(int *col, int *rows);
void			clear_prompt_line(t_mshl *mshl, t_tcntl *term_cntl);

void			tc_init_attr(t_tcntl *term_cntl);
int				termcap_control(t_mshl *mshl, t_tcntl *term_cntl);

int				putchar_tc(int tc);
void			delete_end(t_tcntl *term_cntl);
void			eof_sequence(t_mshl *mshl, t_tcntl *term_cntl);
void			fetch_older_history(t_mshl *mshl, t_tcntl *term_cntl);
void			fetch_newer_history(t_mshl *mshl, t_tcntl *term_cntl);

#endif
