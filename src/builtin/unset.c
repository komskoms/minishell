/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:55:09 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/07 13:38:38 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_struct.h"

int					builtin_unset(void *pack, char **argv)
{
	t_pair				*pair;
	int					index;
	t_mshl				*mshl;

	mshl = (t_mshl *)pack;
	index = 0;
	while (argv[index])
	{
		pair = hashmap_pop(mshl->env_hashmap, argv[index]);
		if (!pair)
			pair = hashmap_pop(mshl->var_hashmap, argv[index]);
		if (pair)
			pair_clear(pair);
		index++;
	}
	return (0);
}
