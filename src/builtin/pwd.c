/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:09:49 by jihoon            #+#    #+#             */
/*   Updated: 2021/06/06 15:36:36 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			builtin_pwd(t_mshl *mshl, char **argv)
{
	char	str[1024];

	no_point_but_norm((void **)mshl);
	no_point_but_norm((void **)argv);
	if (!getcwd(str, 1024))
		return (1);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	return (0);
}
