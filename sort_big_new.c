/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:14:47 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/10 13:32:43 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis(t_dlist **a);

static void	initial_push(t_data *dat)
{
	while (dat->a != dat->min)
	{
		if (dat->a->lis == 1)
		{
			if (dat->min == NULL)
				dat->min = dat->a;
			else if (dat->min->num > dat->a->num)
				dat->min = dat->a;
			oper_select(dat, ROT_A);
		}
		else
			oper_select(dat, PUSH_B);
	}
}



void	sort_new(t_data **dat, t_dlist **min)
{
	int		move_arr[5];
	t_dlist	*curr;
	t_dlist	*best;

	move_arr[0] = 0;
	curr = (*dat)->b;
	while (1)
	{
		
	}
}

void	sort_big_new(t_data *dat)
{
	t_dlist	*min;

	min = NULL;
	lis(&(dat->a));
	initial_push(dat);
	while (!is_sorted(dat->a))
		rotate_calc(dat, NULL);
}
