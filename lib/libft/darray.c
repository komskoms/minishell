/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:08:26 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/05/28 17:23:01 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						darray_element_count(char **darray)
{
	int					index;

	index = 0;
	while (darray[index])
		index++;
	return (index);
}

void					drop_darray(char ***darray)
{
	int					index;
	char				**temp;

	index = 0;
	temp = *darray;
	if (!temp)
		return ;
	while (temp[index])
	{
		free(temp[index]);
		index++;
	}
	free(temp);
	*darray = NULL;
}

char					*list_to_darray(char ***out, t_list *list)
{
	int					index;
	char				**darray;
	char				*dup;

	index = 0;
	darray = (char **)malloc(sizeof(char *) * (ft_lstsize(list) + 1));
	while (list)
	{
		dup = NULL;
		if (!replace((void **)&dup, ft_strdup(list->content)))
		{
			drop_darray(&darray);
			return (NULL);
		}
		darray[index] = dup;
		list = list->next;
		index++;
	}
	darray[index] = NULL;
	*out = darray;
	return (**out);
}

t_list					*darray_to_list(t_list **list, char **darray)
{
	t_list				*new;
	int					index;

	index = 0;
	if (!darray)
		return (NULL);
	while (darray[index])
	{
		if (!init((void **)&new, sizeof(t_list)))
			return (NULL);
		if (!replace(&new->content, ft_strdup(darray[index])))
		{
			free(new);
			return (NULL);
		}
		ft_lstadd_back(list, new);
		index++;
	}
	return (*list);
}
