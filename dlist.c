/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:07:06 by acourtar          #+#    #+#             */
/*   Updated: 2023/01/11 15:48:47 by acourtar         ###   ########.fr       */
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
	new->next = new;
	new->prev = new;
	new->num = num;
	return (new);
}

void	dlist_push(t_dlist *list, t_dlist *new)
{
	t_dlist	*start;

	if (list == NULL)
	{
		list = new;
		ft_printf("ey: %p\n", list);
		return ;
	}
	start = list;
	list = list->prev;
	list->next = new;
	new->prev = list;
	new->next = start;
	start->prev = new;
}

void	dlist_pop(t_dlist **list)
{
	t_dlist	*head;

	if (*list == NULL)
		return ;
	if (*list == (*list)->next)
	{
		free(*list);
		*list = NULL;
	}
	else
	{
		head = (*list)->prev;
		head->prev->next = *list;
		(*list)->prev = head->prev;
		free(head);
	}
}
