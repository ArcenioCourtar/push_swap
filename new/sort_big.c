/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:36:49 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/01 19:57:16 by acourtar         ###   ########.fr       */
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
			else if ((*min)->num > dat->a->num)
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

// static void	insertion_sort(t_data *dat, t_dlist **min)
// {
// 	while (dat->b != NULL)
// 	{
// 		if (correct_loc_min(dat->a, dat->b, min))
// 			oper_select(dat, PUSH_A);
// 		else
// 			rotate_calc(dat, (*min));
// 	}
// }

int	stepcount_b(int steptmp, int len)
{
	if (steptmp > len / 2)
		return (len - steptmp);
	else
		return (steptmp);
}

int	stepcounter(t_data *dat, t_dlist *curr, t_dlist *min)
{
	int		result;
	int		steptmp;
	int		len;
	t_dlist	*tmpptr;

	tmpptr = curr;
	len = dlist_count(dat->b);
	steptmp = 0;
	while (dat->b != tmpptr)
	{
		steptmp++;
		tmpptr = tmpptr->next;
	}
	result = stepcount_b(steptmp, len);
	steptmp = 0;
	tmpptr = dat->a;
	len = dlist_count(dat->a);
	while (!correct_loc(tmpptr, curr, min))
	{
		steptmp++;
		tmpptr = tmpptr->next;
	}
	result += stepcount_b(steptmp, len) + 1;
	return (result);
}

void	rotate_b(t_data *dat, int steps, int len)
{
	// ft_printf("rotb, steps: %i, len: %i\n", steps, len);
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

void	rotate_a(t_data *dat, int steps, int len)
{
	// ft_printf("rota, steps: %i, len: %i\n", steps, len);
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

void	ins_back(t_data **dat, t_dlist *shortptr, t_dlist **min)
{
	int		steps;
	int		len;
	t_dlist	*tmpptr;

	tmpptr = (*dat)->b;
	len = dlist_count((*dat)->b);
	steps = 0;
	// ft_printf("tmp: %i, short: %i\n", tmpptr->num, shortptr->num);
	while (tmpptr != shortptr)
	{
		steps++;
		tmpptr = tmpptr->next;
	}
	rotate_b((*dat), steps, len);
	tmpptr = (*dat)->a;
	len = dlist_count((*dat)->a);
	steps = 0;
	while (!correct_loc_min(tmpptr, (*dat)->b, min))
	{
		steps++;
		tmpptr = tmpptr->next;
	}
	rotate_a((*dat), steps, len);
}

void	new_sort(t_data **dat, t_dlist **min)
{
	t_dlist	*curr;
	t_dlist	*shortptr;
	int		low;
	int		steptmp;

	while ((*dat)->b != NULL)
	{
		low = 0;
		curr = (*dat)->b;
		// dlist_view((*dat)->a);
		// dlist_view((*dat)->b);
		while (1)
		{
			steptmp = stepcounter((*dat), curr, (*min));
			// ft_printf("steptmp: %i, curr: %i\n", steptmp, curr->num);
			if (low == 0 || steptmp < low)
			{
				// ft_printf("NEWPTR\n");
				low = steptmp;
				shortptr = curr;
			}
			curr = curr->next;
			if (curr == (*dat)->b)
				break ;
		}
		ins_back(dat, shortptr, min);
	}
}

void	sort_big(t_data *dat)
{
	t_dlist	*min;

	min = NULL;
	lis(&(dat->a));
	initial_push(dat, &min);
	// insertion_sort(dat, &min);
	new_sort(&dat, &min);
	while (!is_sorted(dat->a))
	{
		rotate_calc(dat, NULL);
	}
}
