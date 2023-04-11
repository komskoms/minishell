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

void	delete_end(t_tcntl *term_cntl)
{
	if (term_cntl->c_pos[0] == term_cntl->i_pos[0])
		return ;
	term_cntl->ln_idx--;
	term_cntl->c_pos[0]--;
	tputs(tgoto(term_cntl->cm, term_cntl->c_pos[0], term_cntl->c_pos[1])
		, 1, putchar_tc);
	tputs(term_cntl->ce, 1, putchar_tc);
}

t_dlist	*get_dlist_index(t_dlist *head, int idx)
{
	if (!head || idx < 0)
		return (0);
	while (idx--)
		head = head->next;
	return (head);
}

void	fetch_older_history(t_mshl *mshl, t_tcntl *term_cntl)
{
	t_dlist		*target;

	if (!mshl->history || (term_cntl->his_idx >= mshl->history_size - 1))
		return ;
	tputs(tgoto(term_cntl->cm, term_cntl->i_pos[0], term_cntl->i_pos[1])
		, 1, putchar_tc);
	tputs(term_cntl->ce, 1, putchar_tc);
	if (term_cntl->his_idx >= 0)
		free(mshl->line);
	term_cntl->his_idx++;
	target = get_dlist_index(mshl->history, term_cntl->his_idx);
	mshl->line = strdup_bybuffersize(target->content);
	term_cntl->ln_idx = ft_strlen(mshl->line);
	ft_putstr_fd(mshl->line, 1);
}

void	fetch_newer_history(t_mshl *mshl, t_tcntl *term_cntl)
{
	t_dlist		*target;

	if (!mshl->history || term_cntl->his_idx == -1)
		return ;
	tputs(tgoto(term_cntl->cm, term_cntl->i_pos[0], term_cntl->i_pos[1])
		, 1, putchar_tc);
	tputs(term_cntl->ce, 1, putchar_tc);
	if (term_cntl->his_idx >= 0)
		free(mshl->line);
	term_cntl->his_idx--;
	target = get_dlist_index(mshl->history, term_cntl->his_idx);
	if (target)
		mshl->line = strdup_bybuffersize(target->content);
	else
		mshl->line = term_cntl->line_ori;
	term_cntl->ln_idx = ft_strlen(mshl->line);
	ft_putstr_fd(mshl->line, 1);
}
