/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_transform_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:51:16 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/07 18:58:45 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		transform_to_command(t_dlist *list)
{
	while (list)
	{
		if (*((t_wrap *)list->content)->type == *MS_ENV)
			((t_wrap *)list->content)->type = MS_CMD;
		list = list->next;
	}
}

void			transform_env(t_dlist *list)
{
	if (list)
	{
		if (*((t_wrap *)list->content)->type != *MS_ENV)
			transform_to_command(list);
	}
}
