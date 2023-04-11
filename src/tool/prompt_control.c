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

int		prompt_loop(t_mshl *mshl, t_tcntl *term_cntl)
{
	int				chk;

	term_cntl->ln_idx = 0;
	while (1)
	{
		term_cntl->ch = 0;
		chk = read(0, &term_cntl->ch, sizeof(int));
		if (chk == -1)
			break ;
		if (termcap_control(mshl, term_cntl))
			continue ;
		mshl->line[term_cntl->ln_idx] = term_cntl->ch;
		if (mshl->line[term_cntl->ln_idx] == '\n' || chk == 0)
			return (last_procedure(&mshl->line, term_cntl->ln_idx));
		if (++term_cntl->ln_idx == BUFFER_SIZE)
		{
			if (!(lengthen_line(&mshl->line, term_cntl->ln_idx)))
				break ;
		}
	}
	return (-1);
}

int		prompt_handler(t_mshl *mshl)
{
	t_tcntl			term_cntl;
	int				ret;

	if (BUFFER_SIZE < 1)
		return (-1);
	if (!init_line(&mshl->line))
		return (-1);
	tc_init_attr(&term_cntl);
	term_cntl.line_ori = mshl->line;
	ret = prompt_loop(mshl, &term_cntl);
	tcsetattr(STDIN_FILENO, TCSANOW, &term_cntl.ori_term);
	if (ret == -1 || term_cntl.his_idx != -1)
		free(term_cntl.line_ori);
	return (ret);
}
