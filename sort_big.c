/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:36:49 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/21 16:39:20 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorting.h"

// might be able to improve this by comparing pairs to the lis
// members surrounding them, and swapping them if it results 
// in a larger lis
static void	initial_push(t_dlist **a, t_dlist **b, t_dlist **min)
{
	while ((*a) != (*min))
	{
		if ((*a)->lis == 1)
		{
			if ((*min) == NULL)
				(*min) = (*a);
			oper_select(a, NULL, ROT_A);
		}
		else
		{
			oper_select(a, b, PUSH_B);
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

static void	insertion_sort(t_dlist **a, t_dlist **b, t_dlist **min)
{
	while ((*b) != NULL)
	{
		if (correct_loc_min((*a), (*b), min))
			oper_select(a, b, PUSH_A);
		else
			oper_select(a, b, ROT_A);
	}
}

void	sort_big(t_dlist **a, t_dlist **b)
{
	t_dlist	*min;

	min = NULL;
	lis(a);
	initial_push(a, b, &min);
	insertion_sort(a, b, &min);
	while (!is_sorted(*a))
		oper_select(a, b, ROT_A);
}
