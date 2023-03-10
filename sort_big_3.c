/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:34:55 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/10 13:30:25 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stepcount_tmp(int steptmp, int len)
{
	if (steptmp > len / 2)
		return (len - steptmp);
	else
		return (steptmp);
}

static void	rotate_b(t_data *dat, int steps, int len)
{
	if (steps > len / 2)
	{
		while (steps < len)
		{
			oper_select(dat, RROT_B);
			steps++;
		}
	}
	else
	{
		while (steps > 0)
		{
			oper_select(dat, ROT_B);
			steps--;
		}
	}
}

static void	rotate_a(t_data *dat, int steps, int len)
{
	if (steps > len / 2)
	{
		while (steps < len)
		{
			oper_select(dat, RROT_A);
			steps++;
		}
	}
	else
	{
		while (steps > 0)
		{
			oper_select(dat, ROT_A);
			steps--;
		}
	}
	oper_select(dat, PUSH_A);
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

void	ins_back(t_data *dat, t_dlist *shortptr)
{
	int		steps;
	int		len;
	t_dlist	*tmpptr;

	tmpptr = dat->b;
	len = dlist_count(dat->b);
	steps = 0;
	while (tmpptr != shortptr)
	{
		steps++;
		tmpptr = tmpptr->next;
	}
	rotate_b(dat, steps, len);
	tmpptr = dat->a;
	len = dlist_count(dat->a);
	steps = 0;
	while (!correct_loc_min(tmpptr, dat->b, &(dat->min)))
	{
		steps++;
		tmpptr = tmpptr->next;
	}
	rotate_a(dat, steps, len);
}
