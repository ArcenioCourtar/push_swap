/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:40:42 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/21 16:53:24 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_dlist **a)
{
	if ((*a)->num > (*a)->next->num)
		oper_select(a, NULL, SWAP_A);
}

void	sort_three(t_dlist **a)
{
	int	num[3];

	num[0] = (*a)->num;
	num[1] = (*a)->next->num;
	num[2] = (*a)->next->next->num;
	if (num[0] < num[1] && num[0] < num[2] && num[1] > num[2])
	{
		oper_select(a, NULL, SWAP_A);
		oper_select(a, NULL, ROT_A);
	}
	else if (num[0] > num[1] && num[0] < num[2])
		oper_select(a, NULL, SWAP_A);
	else if (num[0] < num[1] && num[0] > num[2])
		oper_select(a, NULL, RROT_A);
	else if (num[0] > num[1] && num[0] > num[2])
	{
		if (num[1] < num[2])
			oper_select(a, NULL, ROT_A);
		else
		{
			oper_select(a, NULL, SWAP_A);
			oper_select(a, NULL, RROT_A);
		}
	}
}

static int	correct_loc(t_dlist *a, t_dlist *b, t_dlist *min)
{
	if (b == NULL && is_sorted(a))
		return (1);
	else if (min != NULL)
	{
		if (a->prev->num < b->num && b->num < a->num)
			return (1);
		else if (a->prev->num < b->num && a == min)
			return (1);
		else if (b->num < a->num && a == min)
			return (1);
	}
	return (0);
}

// bruh
static void	rotate_calc(t_dlist **a, t_dlist **b, t_dlist *min)
{
	t_dlist	*ptr;
	int		steps;
	int		len;

	steps = 0;
	ptr = (*a);
	len = dlist_count((*a));
	while (!correct_loc(ptr, (*b), min))
	{
		steps++;
		ptr = ptr->next;
	}
	if (steps > len / 2)
	{
		while (steps < len)
		{
			oper_select(a, NULL, RROT_A);
			steps++;
		}
	}
	else
	{
		while (steps > 0)
		{
			oper_select(a, NULL, ROT_A);
			steps--;
		}
	}
}

static void	sort_five_helper(t_dlist **a, t_dlist **b)
{
	t_dlist	*min;

	min = (*a);
	while ((*b) != NULL)
	{
		if ((*b)->num < (*a)->num && (*a) == min)
		{
			oper_select(a, b, PUSH_A);
			min = (*a);
		}
		else if ((*b)->num < (*a)->num && (*b)->num > (*a)->prev->num)
			oper_select(a, b, PUSH_A);
		else if ((*b)->num > (*a)->prev->num && (*a) == min)
			oper_select(a, b, PUSH_A);
		else
		{
			rotate_calc(a, b, min);
		}
	}
}

void	sort_five(t_dlist **a, t_dlist **b, int len)
{
	while (len > 3)
	{
		oper_select(a, b, PUSH_B);
		len--;
	}
	sort_three(a);
	sort_five_helper(a, b);
	if (!is_sorted(*a))
		rotate_calc(a, b, NULL);
}
