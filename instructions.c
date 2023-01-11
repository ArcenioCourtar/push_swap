/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:12:26 by acourtar          #+#    #+#             */
/*   Updated: 2023/01/11 15:04:09 by acourtar         ###   ########.fr       */
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
	*list = (*list)->prev;
}

void	instr_rrot(t_dlist **list)
{
	*list = (*list)->next;
}

void	instr_push(t_dlist **src, t_dlist **dest)
{
	t_dlist	*copy;

	copy = dlist_new((*src)->prev->num);
	dlist_push(*dest, copy);
	dlist_pop(src);
}
