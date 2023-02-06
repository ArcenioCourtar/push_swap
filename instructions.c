/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:12:26 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/06 13:24:19 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h> // write()

static void	instr_swap(t_dlist **list, int mode)
{
	t_dlist	*top;
	t_dlist	*below;
	int		temp;

	print_instr(mode);
	if (*list == NULL)
		return ;
	top = (*list)->prev;
	below = (*list)->prev->prev;
	temp = top->num;
	top->num = below->num;
	below->num = temp;
}

static void	instr_rot(t_dlist **list, int mode)
{
	print_instr(mode);
	if (*list == NULL)
		return ;
	*list = (*list)->prev;
}

static void	instr_rrot(t_dlist **list, int mode)
{
	print_instr(mode);
	if (*list == NULL)
		return ;
	*list = (*list)->next;
}

static void	instr_push(t_dlist **src, t_dlist **dest, int mode)
{
	t_dlist	*copy;

	print_instr_push(mode);
	if (*src == NULL)
		return ;
	copy = dlist_new((*src)->prev->num);
	if (*dest == NULL)
		*dest = copy;
	else
		dlist_add(*dest, copy);
	dlist_pop(src);
}

void	instr_select(t_dlist **list_a, t_dlist **list_b, int mode)
{
	if (mode <= SWAP_S)
	{
		if (mode == SWAP_A || mode == SWAP_S)
			instr_swap(list_a, mode);
		if (mode == SWAP_B || mode == SWAP_S)
			instr_swap(list_b, mode);
	}
	else if (mode == PUSH_A)
		instr_push(list_b, list_a, mode);
	else if (mode == PUSH_B)
		instr_push(list_a, list_b, mode);
	else if (mode <= ROT_R)
	{
		if (mode == ROT_A || mode == ROT_R)
			instr_rot(list_a, mode);
		if (mode == ROT_B || mode == ROT_R)
			instr_rot(list_b, mode);
	}
	else if (mode <= RROT_R)
	{
		if (mode == RROT_A || mode == RROT_R)
			instr_rrot(list_a, mode);
		if (mode == RROT_B || mode == RROT_R)
			instr_rrot(list_b, mode);
	}
}
