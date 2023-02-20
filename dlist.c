/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:07:06 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/20 16:36:47 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h> // malloc, free
#include <unistd.h> // write

// Initialize new node to add to the list.
t_dlist	*dlist_new(int num)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (new == NULL)
		return (NULL);
	new->next = new;
	new->prev = new;
	new->num = num;
	new->stack = 1;
	new->stknext = NULL;
	new->stkprev = NULL;
	new->stkup = NULL;
	new->stkdown = NULL;
	new->listptr = NULL;
	return (new);
}

// Add newly created node to the list. Becomes the new "first" element.
void	dlist_add(t_dlist **list, t_dlist *new)
{
	if (*list == NULL)
	{
		new->next = new;
		new->prev = new;
		*list = new;
		return ;
	}
	new->next = *list;
	new->prev = (*list)->prev;
	(*list)->prev = new;
	new->prev->next = new;
	*list = new;
}

// Remove the current first element from the list, by pointing the 
// elements around it to each other. Then free the first element.
// NOTE: Might not be needed with my new implementation.
void	dlist_pop(t_dlist **list)
{
	t_dlist	*old_head;

	if (*list == NULL)
		return ;
	old_head = (*list);
	if ((*list)->next == *list)
	{
		free(*list);
		*list = NULL;
	}
	else
	{
		(*list)->next->prev = (*list)->prev;
		(*list)->prev->next = (*list)->next;
		*list = (*list)->next;
		free(old_head);
	}
}

// Count number of elements in list
int	dlist_count(t_dlist *list)
{
	t_dlist	*start;
	int		i;

	i = 1;
	start = list;
	if (list == NULL)
		return (0);
	else
	{
		while (list->next != start)
		{
			i++;
			list = list->next;
		}
		return (i);
	}
}
