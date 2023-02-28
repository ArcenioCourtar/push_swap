/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:12:26 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/28 17:17:28 by acourtar         ###   ########.fr       */
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
// Select which list based on mode.
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

// Rotate elements in the list.
// Select which list and which direction based on mode.
// ROT = first elem becomes last.
// RROT = last elem becomes first.
static void	oper_rot(t_data *dat, int mode)
{
	t_dlist	**list;

	oper_add(dat, mode);
	if (mode == ROT_A || mode == RROT_A)
		list = &(dat->a);
	else
		list = &(dat->b);
	if (*list == NULL)
		return ;
	if (mode == ROT_A || mode == ROT_B)
		*list = (*list)->next;
	else
		*list = (*list)->prev;
}

// Move the first element of list "src" to list "dest"
// TODO: make separate C file for helper functions.
static void	oper_push(t_data *dat, int mode)
{
	t_dlist	*move_this;
	t_dlist	**src;
	t_dlist	**dest;

	oper_add(dat, mode);
	if (mode == PUSH_A)
	{
		src = &(dat->b);
		dest = &(dat->a);
	}
	else
	{
		src = &(dat->a);
		dest = &(dat->b);
	}
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
	if (mode == SWAP_A || mode == SWAP_B)
		oper_swap(dat, mode);
	else if (mode == PUSH_A || mode == PUSH_B)
		oper_push(dat, mode);
	else if (mode == ROT_A || mode == ROT_B || mode == RROT_A || mode == RROT_B)
		oper_rot(dat, mode);
}
