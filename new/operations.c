/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:12:26 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/28 15:55:07 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "print_oper.h" // separate header for the print_oper() function

// All functions but one in this file are static since I exclusively use the
// oper_select() function to gain access to all of them.

static void	oper_swap_helper(t_dlist **list)
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

// Swap the first two elements in a list.
static void	oper_swap(t_data *dat, int mode)
{
	t_dlist	**list;

	oper_add(dat, mode);
	if (mode == SWAP_A)
		list = &(dat->a);
	else
		list = &(dat->a);
	if (*list == NULL || dlist_count(*list) == 1)
		return ;
	if (dlist_count(*list) == 2)
	{
		(*list) = (*list)->next;
		return ;
	}
	oper_swap_helper(list);
}

// Rotate elements in the list. First element becomes the last.
static void	oper_rot(t_dlist **list, int mode)
{
	print_oper(mode);
	if (*list == NULL)
		return ;
	*list = (*list)->next;
}

// Reverse rotate elements in the list. Last element becomes the first.
static void	oper_rrot(t_dlist **list, int mode)
{
	print_oper(mode);
	if (*list == NULL)
		return ;
	*list = (*list)->prev;
}

// Move the first element of list "src" to list "dest"
static void	oper_push(t_dlist **src, t_dlist **dest, int mode)
{
	t_dlist	*move_this;

	print_oper_push(mode);
	if (*src == NULL)
		return ;
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

// Select which of the above four operations is to be executed
void	oper_select(t_data *dat, int mode)
{
	if (mode == SWAP_A)
		oper_swap(dat, mode);
	else if (mode == SWAP_B)
		oper_swap(dat, mode);
	else if (mode == PUSH_A)
		oper_push(&(dat->b), &(dat->a), mode);
	else if (mode == PUSH_B)
		oper_push(&(dat->a), &(dat->b), mode);
	else if (mode == ROT_A)
		oper_rot(&(dat->a), mode);
	else if (mode == ROT_B)
		oper_rot(&(dat->b), mode);
	else if (mode == RROT_A)
		oper_rrot(&(dat->a), mode);
	else if (mode == RROT_B)
		oper_rrot(&(dat->b), mode);
}
