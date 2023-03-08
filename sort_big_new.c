/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:14:47 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/08 18:07:52 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis(t_dlist **a);

static void	initial_push(t_data *dat, t_dlist **min)
{
	while (dat->a != (*min))
	{
		if (dat->a->lis == 1)
		{
			if ((*min) == NULL)
				(*min) = dat->a;
			else if ((*min)->num > dat->a->num)
				(*min) = dat->a;
			oper_select(dat, ROT_A);
		}
		else
			oper_select(dat, PUSH_B);
	}
}

void	sort_new(t_data **dat, t_dlist **min)
{
	t_dlist	*curr;
	t_dlist	*shortptr;
	int		low;
	int		steptmp;

	while ((*dat)->b != NULL)
	{
		low = 0;
		curr = (*dat)->b;
		while (1)
		{
			// func calculating shortest instruction sequence for curr location
			if (low == 0 || steptmp < low)
			{
				low = steptmp;
				shortptr = curr;
			}
			curr = curr->next;
			if (curr == (*dat)->b)
				break ;
		}
		// func inserting back shortptr
	}
}

void	sort_big_new(t_data *dat)
{
	t_dlist	*min;

	min = NULL;
	lis(&(dat->a));
	initial_push(dat, &min);
	while (!is_sorted(dat->a))
		rotate_calc(dat, NULL);
}
