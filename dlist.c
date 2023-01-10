/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:07:06 by acourtar          #+#    #+#             */
/*   Updated: 2023/01/10 16:12:59 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_dlist	*dlist_new(int num)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->num = num;
	return (new);
}

void	dlist_push(t_dlist **list, t_dlist *new)
{
	t_dlist	*begin;

	begin = *list;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	while ((*list)->next != NULL || (*list)->next == begin)
	{
		list = &(*list)->next;
	}
	new->prev = *list;
	begin->prev = new;
	(**list).next = new;
}
