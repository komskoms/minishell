/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:10:56 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/09 15:16:53 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_struct.h"
#include "minishell.h"

static int				option_map(char *option)
{
	int					result;
	char				*addr;

	result = 0;
	if (!option)
		return (0);
	if (*option == '-')
	{
		option++;
		while (*option)
		{
			addr = ft_strchr(ECHO_OPTION, *option);
			if (!addr)
				return (0);
			result |= 1 << (addr - ECHO_OPTION);
			option++;
		}
	}
	else
		return (0);
	return (result);
}

static void				exception(char *str, t_mshl *mshl)
{
	size_t				strlen;
	t_dlist				*home;
	t_pair				*pair;
	int					offset;

	strlen = ft_strlen(str);
	offset = 0;
	if (*str == '~')
	{
		if ((1 < strlen && *(str + 1) == '/') || strlen == 1)
		{
			home = hashmap_pick(mshl->env_hashmap, "HOME");
			if (home)
			{
				pair = (t_pair *)home->content;
				write(1, pair->val, ft_strlen(pair->val));
			}
			offset++;
		}
	}
	write(1, str + offset, ft_strlen(str + offset));
}

int						builtin_echo(void *pack, char **argv)
{
	int					index;
	int					optn_map;
	t_mshl				*mshl;

	mshl = (t_mshl *)pack;
	if (mshl->line)
		set_error_code(138);
	index = 1;
	optn_map = option_map(argv[index]);
	if (optn_map)
		index++;
	while (argv[index])
	{
		exception(argv[index], mshl);
		index++;
		if (argv[index])
			write(1, " ", 1);
	}
	if (!optn_map)
		write(1, "\n", 1);
	return (0);
}
