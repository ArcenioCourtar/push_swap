/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:39:05 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/07 15:18:26 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Extra file to fulfill the Norm's 5 function per file limit

void	oper_swap_helper(t_dlist **list)
{
	t_dlist	*array[4];
	t_dlist	*first;
	t_dlist	*second;

	first = (*list);
	second = (*list)->next;
	array[0] = first->prev;
	array[1] = second->prev;
	array[2] = first->next;
	array[3] = second->next;
	first->prev = array[2];
	second->prev = array[0];
	first->next = array[3];
	second->next = array[1];
	first->next->prev = first;
	second->prev->next = second;
	(*list) = second;
}

void	oper_push_helper(t_dlist **src, t_dlist **dest)
{
	t_dlist	*move_this;

	move_this = *src;
	if ((*src)->next == *src)
	{
		dlist_add(dest, move_this);
		*src = NULL;
	}
	else
	{
		(*src)->next->prev = (*src)->prev;
		(*src)->prev->next = (*src)->next;
		*src = (*src)->next;
		dlist_add(dest, move_this);
	}
}
