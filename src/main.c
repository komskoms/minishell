/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:59:37 by jihokim           #+#    #+#             */
/*   Updated: 2021/06/07 15:59:38 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_struct.h"

static void	why_norm(int argc, char **argv)
{
	if (argc || argv)
		argc = 0;
}

int			main(int argc, char **argv, char **envp)
{
	t_mshl				mshl;

	why_norm(argc, argv);
	variables_init(&mshl, envp);
	minishell_loop(&mshl);
	drop_mshl(&mshl);
	return (0);
}
