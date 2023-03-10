/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:14:47 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/10 21:13:58 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis(t_dlist **a);

void	calc_low(int arr[5])
{
	arr[4] = arr[0] + arr[3] + 1;
	if (arr[4] > (arr[1] + arr[2]))
		arr[4] = arr[1] + arr[2] + 1;
	if (arr[0] > arr[2])
	{
		if (arr[4] > arr[0])
			arr[4] = arr[0] + 1;
	}
	else
	{
		if (arr[4] > arr[2])
			arr[4] = arr[2] + 1;
	}
	if (arr[1] > arr[3])
	{
		if (arr[4] > arr[1])
			arr[4] = arr[1] + 1;
	}
	else
	{
		if (arr[4] > arr[3])
			arr[4] = arr[3] + 1;
	}
}

void	update_arr(int top_arr[5], int arr[5])
{
	top_arr[0] = arr[0];
	top_arr[1] = arr[1];
	top_arr[2] = arr[2];
	top_arr[3] = arr[3];
	top_arr[4] = arr[4];
}

void	check_prev(t_data *dat, int i, t_dlist *prv, int top_arr[5])
{
	t_dlist	*tmpptr;
	int		arr[5];

	arr[4] = 0;
	arr[1] = 0;
	arr[2] = dlist_count(dat->b) - i;
	arr[3] = i;
	tmpptr = dat->a;
	while (!correct_loc(tmpptr, prv, dat->min))
	{
		arr[1]++;
		tmpptr = tmpptr->prev;
	}
	ft_printf("\ncorrect loc?: %i, %i, %i, min: %i\n", tmpptr->prev->num, prv->num, tmpptr->num, dat->min->num);
	arr[0] = dlist_count(dat->a) - arr[1];
	// ft_printf("a len: %i, rots: %i|b len: %i, rots: %i\n", dlist_count(dat->a), arr[0]+arr[1], dlist_count(dat->b), arr[2]+arr[3]);
	calc_low((arr));
	if (top_arr[4] == 0 || top_arr[4] > arr[4])
		update_arr(top_arr, arr);
	ft_printf("prv i: %i, ra: %i, rra: %i, rb: %i, rrb: %i, low: %i\n", i, arr[0], arr[1], arr[2], arr[3], arr[4]);
}

void	check_next(t_data *dat, int i, t_dlist *nxt, int top_arr[5])
{
	t_dlist	*tmpptr;
	int		arr[5];

	arr[4] = 0;
	arr[0] = 0;
	arr[2] = i;
	arr[3] = dlist_count(dat->b) - i;
	tmpptr = dat->a;
	while (!correct_loc(tmpptr, nxt, dat->min))
	{
		arr[0]++;
		tmpptr = tmpptr->next;
	}
	ft_printf("\ncorrect loc?: %i, %i, %i, min: %i\n", tmpptr->prev->num, nxt->num, tmpptr->num, dat->min->num);
	arr[1] = dlist_count(dat->a) - arr[0];
	ft_printf("a len: %i, rots: %i|b len: %i, rots: %i\n", dlist_count(dat->a), arr[0]+arr[1], dlist_count(dat->b), arr[2]+arr[3]);
	calc_low((arr));
	if (top_arr[4] == 0 || top_arr[4] > arr[4])
		update_arr(top_arr, arr);
	ft_printf("nxt i: %i, ra: %i, rra: %i, rb: %i, rrb: %i, low: %i\n", i, arr[0], arr[1], arr[2], arr[3], arr[4]);
}

// RA, RRA, RB, RRB, MIN
void	calc_fastest(t_data *dat, int orig_arr[5])
{
	t_dlist	*nxt_prv[2];
	int		i;

	i = 0;
	nxt_prv[0] = dat->b;
	nxt_prv[1] = dat->b;
	while (1)
	{
		nxt_prv[0] = nxt_prv[0]->next;
		nxt_prv[1] = nxt_prv[1]->prev;
		check_next(dat, i, nxt_prv[0], orig_arr);
		if (i != 0)
			check_prev(dat, i, nxt_prv[1], orig_arr);
		i++;
		if (i >= orig_arr[4])
			break ;
	}
}

void	sort_new(t_data *dat)
{
	int		orig_arr[5];
	
	orig_arr[4] = 0;
	calc_fastest(dat, orig_arr);
}

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

void	sort_big_new(t_data *dat)
{
	lis(&(dat->a));
	initial_push(dat);
	sort_new(dat);
	// while (!is_sorted(dat->a))
	// 	rotate_calc(dat, NULL);
}
