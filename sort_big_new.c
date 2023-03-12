/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:14:47 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/12 16:23:46 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis(t_dlist **a);
int		correct_loc_min(t_dlist *a, t_dlist *b, t_dlist **min);

int	correct_loc_min(t_dlist *a, t_dlist *b, t_dlist **min)
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
	arr[0] = 0;
	arr[2] = dlist_count(dat->b) - i;
	arr[3] = i;
	tmpptr = dat->a;
	while (!correct_loc(tmpptr, prv, dat->min))
	{
		arr[0]++;
		tmpptr = tmpptr->next;
	}
	if (arr[0] == 0)
		arr[1] = 0;
	else
		arr[1] = dlist_count(dat->a) - arr[1];
	calc_low((arr));
	if (top_arr[4] == 0 || top_arr[4] > arr[4])
		update_arr(top_arr, arr);
}

void	check_next(t_data *dat, int i, t_dlist *nxt, int top_arr[5])
{
	t_dlist	*tmpptr;
	int		arr[5];

	arr[4] = 0;
	arr[0] = 0;
	arr[2] = i;
	if (i == 0)
		arr[3] = i;
	else
		arr[3] = dlist_count(dat->b) - i;
	tmpptr = dat->a;
	while (!correct_loc(tmpptr, nxt, dat->min))
	{
		arr[0]++;
		tmpptr = tmpptr->next;
	}
	if (arr[0] == 0)
		arr[1] = 0;
	else
		arr[1] = dlist_count(dat->a) - arr[0];
	calc_low((arr));
	if (top_arr[4] == 0 || top_arr[4] > arr[4])
		update_arr(top_arr, arr);
}

// RA, RRA, RB, RRB, MIN
void	calc_fastest(t_data *dat, int orig_arr[5])
{
	t_dlist	*nxt_prv[2];
	int		i;
	int		len;

	i = 0;
	len = dlist_count(dat->b);
	nxt_prv[0] = dat->b;
	nxt_prv[1] = dat->b;
	while (1)
	{
		check_next(dat, i, nxt_prv[0], orig_arr);
		if (i != 0)
			check_prev(dat, i, nxt_prv[1], orig_arr);
		nxt_prv[0] = nxt_prv[0]->next;
		nxt_prv[1] = nxt_prv[1]->prev;
		i++;
		if (i >= orig_arr[4] || i > len / 2)
			break ;
	}
}

void	diff_rot(t_data *dat, int a, int b, int mode)
{
	if (mode == ROT_A)
	{
		while (a > 0)
		{
			oper_select(dat, ROT_A);
			a--;
		}
		while (b > 0)
		{
			oper_select(dat, RROT_B);
			b--;
		}
	}
	else
	{
		while (a > 0)
		{
			oper_select(dat, RROT_A);
			a--;
		}
		while (b > 0)
		{
			oper_select(dat, ROT_B);
			b--;
		}
	}
	correct_loc_min(dat->a, dat->b, &(dat->min));
	oper_select(dat, PUSH_A);
}

void	rr_rot(t_data *dat, int a, int b)
{
	while (a > 0 || b > 0)
	{
		if (a > 0 && b > 0)
		{
			oper_select(dat, ROT_R);
			a--;
			b--;
		}
		else if (a > 0)
		{
			oper_select(dat, ROT_A);
			a--;
		}
		else if (b > 0)
		{
			oper_select(dat, ROT_B);
			b--;
		}
	}
	correct_loc_min(dat->a, dat->b, &(dat->min));
	oper_select(dat, PUSH_A);
}

void	rrr_rot(t_data *dat, int a, int b)
{
	while (a > 0 || b > 0)
	{
		if (a > 0 && b > 0)
		{
			oper_select(dat, RROT_R);
			a--;
			b--;
		}
		else if (a > 0)
		{
			oper_select(dat, RROT_A);
			a--;
		}
		else if (b > 0)
		{
			oper_select(dat, RROT_B);
			b--;
		}
	}
	correct_loc_min(dat->a, dat->b, &(dat->min));
	oper_select(dat, PUSH_A);
}

// RA, RRA, RB, RRB, MIN
void	exec_oper(t_data *dat, int arr[5])
{
	if (arr[0] < arr[4] && arr[2] < arr[4])
		rr_rot(dat, arr[0], arr[2]);
	else if (arr[1] < arr[4] && arr[3] < arr[4])
		rrr_rot(dat, arr[1], arr[3]);
	else if (arr[0] + arr[3] == arr[4] - 1)
		diff_rot(dat, arr[0], arr[3], ROT_A);
	else if (arr[1] + arr[2] == arr[4] - 1)
		diff_rot(dat, arr[1], arr[2], ROT_B);
}

void	sort_new(t_data *dat)
{
	int		orig_arr[5];

	while (dat->b != NULL)
	{
		orig_arr[4] = 0;
		calc_fastest(dat, orig_arr);
		exec_oper(dat, orig_arr);
	}
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
	while (!is_sorted(dat->a))
		rotate_calc(dat, NULL);
}
