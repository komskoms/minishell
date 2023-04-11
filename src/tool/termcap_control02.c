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

int		putchar_tc(int tc)
{
	write(1, &tc, 1);
	return (0);
}

void	eof_sequence(t_mshl *mshl, t_tcntl *term_cntl)
{
	if (term_cntl->ln_idx)
		return ;
	ft_putstr_fd("exit\n", 1);
	tcsetattr(STDIN_FILENO, TCSANOW, &term_cntl->ori_term);
	drop_mshl(mshl);
	exit(0);
}

void	clear_prompt_line(t_mshl *mshl, t_tcntl *term_cntl)
{
	int		ln_len;

	if (term_cntl->his_idx != -1)
	{
		free(mshl->line);
		mshl->line = term_cntl->line_ori;
	}
	ln_len = ft_strlen(mshl->line);
	ft_memset(mshl->line, 0, ln_len);
	term_cntl->his_idx = -1;
	term_cntl->ln_idx = 0;
	write(1, "\n", 1);
	show_prompt();
}

void	get_cursor_position(int *col, int *row)
{
	char	buf[255];
	int		ret;
	int		i;

	ret = write(0, TC_GET_CURSOR_POS, 4);
	ret = read(0, buf, 254);
	buf[ret] = '\0';
	i = 0;
	while (buf[i + 1] != ';')
		i++;
	*row = ft_atoi(buf + 2) - 1;
	*col = ft_atoi(buf + 2 + i) - 1;
}

char	*strdup_bybuffersize(char *str)
{
	int		len;
	int		unit;
	char	*ret;

	len = ft_strlen(str);
	unit = len / BUFFER_SIZE + 1;
	ret = ft_calloc(unit * BUFFER_SIZE, sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, str, len + 1);
	return (ret);
}
