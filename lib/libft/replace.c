/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 00:07:23 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/05/29 01:54:28 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void					*replace(void **out, void *src)
{
	if (*out)
		free(*out);
	*out = src;
	return (*out);
}

void					del_content(void *content)
{
	if (content)
		free(content);
}
