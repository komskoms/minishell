/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:47:45 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/08 12:44:17 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					show_prompt(void)
{
	const char			*prompt = "minishell> ";

	write(1, prompt, ft_strlen(prompt));
}
