/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:07:06 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/07 12:03:08 by acourtar         ###   ########.fr       */
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

// View list elements in order.
void	dlist_view(t_dlist *list)
{
	t_dlist	*start;

	if (list == NULL)
	{
		write(STDOUT_FILENO, "(null)\n\n", 8);
		return ;
	}
	start = list;
	while (start != list->next)
	{
		ft_printf("%i, addr: %p, next %p, start %p\n", list->num, list, list->next, start);
		list = list->next;
	}
	ft_printf("%i, addr: %p, next %p, start %p\n\n", list->num, list, list->next, start);
}

// Display number of elements in list.
void	dlist_count(t_dlist *list)
{
	t_dlist	*start;
	int		i;

	i = 1;
	start = list;
	if (list == NULL)
		ft_printf("list length: 0\n");
	else
	{
		while (list->next != start)
		{
			i++;
			list = list->next;
		}
		ft_printf("List length: %i\n", i);
	}
}
