/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:12:26 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/06 17:00:37 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "print_oper.h"

// All functions but one in this file are static since I exclusively use the
// oper_select() function to gain access to all of them.

// Swap the first two elements in a list.
static void	oper_swap(t_dlist **list, int mode)
{
	int	temp;

	print_oper(mode);
	if (*list == NULL)
		return ;
	temp = (*list)->num;
	(*list)->num = (*list)->next->num;
	(*list)->next->num = temp;
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
	t_dlist	*copy;

	print_oper_push(mode);
	if (*src == NULL)
		return ;
	copy = dlist_new((*src)->num);
	if (*dest == NULL)
		*dest = copy;
	else
		dlist_add(dest, copy);
	dlist_pop(src);
}

// Select which of the above four operations is to be executed
void	oper_select(t_dlist **list_a, t_dlist **list_b, int mode)
{
	if (mode <= SWAP_S)
	{
		if (mode == SWAP_A || mode == SWAP_S)
			oper_swap(list_a, mode);
		if (mode == SWAP_B || mode == SWAP_S)
			oper_swap(list_b, mode);
	}
	else if (mode == PUSH_A)
		oper_push(list_b, list_a, mode);
	else if (mode == PUSH_B)
		oper_push(list_a, list_b, mode);
	else if (mode <= ROT_R)
	{
		if (mode == ROT_A || mode == ROT_R)
			oper_rot(list_a, mode);
		if (mode == ROT_B || mode == ROT_R)
			oper_rot(list_b, mode);
	}
	else if (mode <= RROT_R)
	{
		if (mode == RROT_A || mode == RROT_R)
			oper_rrot(list_a, mode);
		if (mode == RROT_B || mode == RROT_R)
			oper_rrot(list_b, mode);
	}
}
