/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:06:07 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/04 15:35:00 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int					is_builtin(t_mshl *mshl, char *cmd)
{
	t_dlist				*pick;
	char				*value;

	pick = hashmap_pick(mshl->cmd_hashmap, cmd);
	if (pick)
	{
		value = (char *)((t_pair *)pick->content)->val;
		return (ft_atoi(value) + 1);
	}
	return (0);
}
