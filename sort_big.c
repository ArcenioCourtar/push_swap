/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:36:49 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/07 15:38:46 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis(t_dlist **a);
void	sort(t_data **dat, t_dlist **min);

// might be able to improve this by comparing pairs to the lis
// members surrounding them, and swapping them if it results 
// in a larger lis
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

void	sort_big(t_data *dat)
{
	t_dlist	*min;

	min = NULL;
	lis(&(dat->a));
	initial_push(dat, &min);
	sort(&dat, &min);
	while (!is_sorted(dat->a))
		rotate_calc(dat, NULL);
}
