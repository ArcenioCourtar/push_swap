/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:14:47 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/08 16:17:22 by acourtar         ###   ########.fr       */
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

void	sort_big_new(t_data *dat)
{
	t_dlist	*min;

	min = NULL;
	lis(&(dat->a));
	initial_push(dat, &min);
	while (!is_sorted(dat->a))
		rotate_calc(dat, NULL);
}
