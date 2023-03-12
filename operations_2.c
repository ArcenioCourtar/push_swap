/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:39:05 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/12 19:02:55 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
since the nodes we're swapping are always adjacent, there's only one way
they can end up after swapping.
A == top,
B == next num.

     A B               A B 
prev 0 1    =>    prev 2 0
next 2 3          next 3 1

Use this matrix to determine where the pointers should end up,
Then just make sure the outer next/prev elements are pointing to the correct
thing as well. 
*/
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

// Use the dlist_add function to add src node to dest list.
// Make sure the nodes in list src are properly reconnected, set to NULL
// in case it's the last node in the list.
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
