/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:08:57 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/02/02 05:20:26 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*rst;

	if (!(rst = (t_list *)malloc(sizeof(t_list))))
	{
		return (NULL);
	}
	rst->content = content;
	rst->next = NULL;
	return (rst);
}
