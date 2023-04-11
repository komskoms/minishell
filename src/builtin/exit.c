/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:09:54 by jihoon            #+#    #+#             */
/*   Updated: 2021/06/09 10:28:02 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_exitcode(char *str)
{
	if (!ft_isdigit(*str))
		return (-1);
	return (ft_atoi(str));
}

int			builtin_exit(t_mshl *mshl, char **argv)
{
	int		argc;
	int		code;

	argc = 0;
	while (argv[argc])
		argc++;
	if (argc > 2)
		return (int_set_error_code(143, 1));
	else if (argc == 2)
		code = get_exitcode(argv[1]);
	else
		code = 0;
	drop_mshl(mshl);
	if (code == -1)
	{
		int_set_error_code(144, 1);
		dispose_error();
		exit(1);
	}
	exit(code);
	return (0);
}
