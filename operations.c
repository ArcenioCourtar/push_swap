/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:12:26 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/12 17:23:19 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	oper_swap_helper(t_dlist **list);
void	oper_push_helper(t_dlist **src, t_dlist **dest);
void	print_oper(int mode);

// Swap the first two elements in a list.
// Select which list based on mode.
static void	oper_swap(t_data *dat, int mode)
{
	t_dlist		**list;

	print_oper(mode);
	while (1)
	{
		if (mode == SWAP_A || mode == SWAP_S)
			list = &(dat->a);
		else
			list = &(dat->b);
		if (*list == NULL || dlist_count(*list) == 1)
			return ;
		if (dlist_count(*list) == 2)
			(*list) = (*list)->next;
		else
			oper_swap_helper(list);
		if (mode == SWAP_S)
		{
			mode = SWAP_B;
			continue ;
		}
		break ;
	}
}

// Rotate elements in the list.
// Select which list and which direction based on mode.
// ROT = first elem becomes last.
// RROT = last elem becomes first.
static void	oper_rot(t_data *dat, int mode)
{
	t_dlist		**list;
	static int	both = 0;

	print_oper(mode);
	if (mode == ROT_R || mode == RROT_R)
		both = 1;
	while (1)
	{
		if (mode == ROT_A || mode == RROT_A || mode == ROT_R || mode == RROT_R)
			list = &(dat->a);
		else
			list = &(dat->b);
		if (mode == ROT_A || mode == ROT_B || mode == ROT_R)
			*list = (*list)->next;
		else
			*list = (*list)->prev;
		if (both == 1)
		{
			mode--;
			both = 0;
			continue ;
		}
		break ;
	}
}

// Move the first element of list "src" to list "dest"
// TODO: make separate C file for helper functions.
static void	oper_push(t_data *dat, int mode)
{
	t_dlist	**src;
	t_dlist	**dest;

	print_oper(mode);
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
	if (mode == SWAP_A || mode == SWAP_B || mode == SWAP_S)
		oper_swap(dat, mode);
	else if (mode == PUSH_A || mode == PUSH_B)
		oper_push(dat, mode);
	else if (mode == ROT_A || mode == ROT_B || mode == RROT_A \
	|| mode == RROT_B || mode == ROT_R || mode == RROT_R)
		oper_rot(dat, mode);
}
