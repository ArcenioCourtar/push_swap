/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:12:26 by acourtar          #+#    #+#             */
/*   Updated: 2023/01/10 18:08:57 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instr_swap(t_dlist *list)
{
	t_dlist	*top;
	t_dlist	*below;
	int		temp;

	top = list->prev;
	below = list->prev->prev;
	temp = top->num;
	top->num = below->num;
	below->num = temp;
}

void	instr_rot(t_dlist **list)
{
	t_dlist	*begin;
	int		temp;

	begin = *list;
	while ((*list)->next != begin)
	{
		temp = (*list)->next->num;
		(*list)->next->num = (*list)->num;
		(*list) = (*list)->next;
		(*list)->num = temp;
	}
}

void	instr_rrot(t_dlist **list)
{
	t_dlist	*begin;
	int		temp;

	begin = *list;
	while ((*list)->prev != begin)
	{
		temp = (*list)->prev->num;
		(*list)->prev->num = (*list)->num;
		(*list) = (*list)->prev;
		(*list)->num = temp;
	}
}
