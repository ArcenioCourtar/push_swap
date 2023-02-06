/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:07:06 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/06 15:20:40 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h> // malloc, free
#include <unistd.h> // write

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

void	dlist_add(t_dlist **list, t_dlist *new)
{
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	new->next = *list;
	new->prev = (*list)->prev;
	(*list)->prev = new;
	new->prev->next = new;
	*list = new;
}

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
		ft_printf("%i\n", list->num);
		list = list->next;
	}
	ft_printf("%i\n\n", list->num);
}

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
			i++;
		ft_printf("List length: %i\n", i);
	}
}
