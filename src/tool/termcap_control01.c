/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap_control00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:10:25 by jihoon            #+#    #+#             */
/*   Updated: 2021/06/04 11:10:26 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "termcap_control.h"

void	tc_init_attr(t_tcntl *term_cntl)
{
	tcgetattr(STDIN_FILENO, &term_cntl->ori_term);
	tcgetattr(STDIN_FILENO, &term_cntl->term);
	term_cntl->term.c_lflag &= ~ICANON;
	term_cntl->term.c_lflag &= ~ECHO;
	term_cntl->term.c_iflag &= ICRNL;
	term_cntl->term.c_cc[VINTR] = 0;
	term_cntl->term.c_cc[VQUIT] = 0;
	term_cntl->term.c_cc[VMIN] = 1;
	term_cntl->term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &term_cntl->term);
	term_cntl->env_term = getenv("TERM");
	if (!term_cntl->env_term)
		term_cntl->env_term = "xterm";
	tgetent(NULL, term_cntl->env_term);
	term_cntl->his_idx = -1;
	term_cntl->cm = tgetstr("cm", NULL);
	term_cntl->ce = tgetstr("ce", NULL);
	get_cursor_position(&term_cntl->i_pos[0], &term_cntl->i_pos[1]);
}

int		termcap_control(t_mshl *mshl, t_tcntl *term_cntl)
{
	get_cursor_position(&term_cntl->c_pos[0], &term_cntl->c_pos[1]);
	if (term_cntl->ch == UP_ARROW)
		fetch_older_history(mshl, term_cntl);
	else if (term_cntl->ch == DOWN_ARROW)
		fetch_newer_history(mshl, term_cntl);
	else if (term_cntl->ch == BACKSPACE)
		delete_end(term_cntl);
	else if (term_cntl->ch == EOF_KEY)
		eof_sequence(mshl, term_cntl);
	else if (term_cntl->ch == 3)
		clear_prompt_line(mshl, term_cntl);
	else if (!(ft_isprint(term_cntl->ch) || term_cntl->ch == '\n'))
		;
	else
	{
		write(1, &term_cntl->ch, 1);
		return (0);
	}
	term_cntl->ch = 0;
	return (1);
}
