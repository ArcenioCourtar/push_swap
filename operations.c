/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:12:26 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/07 14:56:31 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	oper_swap_helper(t_dlist **list);
void	oper_push_helper(t_dlist **src, t_dlist **dest);

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
	oper_push_helper(src, dest);
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
