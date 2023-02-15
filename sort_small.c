/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:40:42 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/15 18:22:25 by acourtar         ###   ########.fr       */
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

int	correct_loc(t_dlist *ptr, t_dlist *b, t_dlist *max)
{
	if (b == NULL && is_sorted(ptr))
		return (1);
	else if (max != NULL)
	{
		if (b->num < ptr->num && ptr->prev == max)
			return (1);
		else if (b->num < ptr->num && b->num > ptr->prev->num)
			return (1);
		else if (b->num > max->num && ptr->prev == max)
			return (1);
	}
	return (0);
}

// bruh
static void	rotate_calc(t_dlist **a, t_dlist **b, t_dlist *max)
{
	t_dlist	*ptr;
	int		steps;
	int		len;

	steps = 0;
	ptr = (*a);
	len = dlist_count((*a));
	while (!correct_loc(ptr, (*b), max))
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
	t_dlist	*max;

	max = (*a)->prev;
	while ((*b) != NULL)
	{
		if ((*b)->num < (*a)->num && (*a)->prev == max)
			oper_select(a, b, PUSH_A);
		else if ((*b)->num < (*a)->num && (*b)->num > (*a)->prev->num)
			oper_select(a, b, PUSH_A);
		else if ((*b)->num > max->num && (*a)->prev == max)
		{
			oper_select(a, b, PUSH_A);
			max = (*a);
		}
		else
		{
			rotate_calc(a, b, max);
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
