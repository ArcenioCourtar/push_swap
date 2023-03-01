/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:36:49 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/01 13:17:25 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorting.h"

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
			oper_select(dat, ROT_A);
		}
		else
		{
			oper_select(dat, PUSH_B);
		}
	}
}

static int	correct_loc_min(t_dlist *a, t_dlist *b, t_dlist **min)
{
	if (b == NULL && is_sorted(a))
		return (1);
	if (a->prev->num < b->num && b->num < a->num)
		return (1);
	else if (a->prev->num < b->num && a == (*min))
		return (1);
	else if (b->num < a->num && a == (*min))
	{
		(*min) = b;
		return (1);
	}
	return (0);
}

static void	insertion_sort(t_data *dat, t_dlist **min)
{
	while (dat->b != NULL)
	{
		if (correct_loc_min(dat->a, dat->b, min))
			oper_select(dat, PUSH_A);
		else
			rotate_calc(dat, (*min));
	}
}

void	sort_big(t_data *dat)
{
	t_dlist	*min;

	min = NULL;
	lis(&(dat->a));
	initial_push(dat, &min);
	insertion_sort(dat, &min);
	while (!is_sorted(dat->a))
		rotate_calc(dat, NULL);
}
