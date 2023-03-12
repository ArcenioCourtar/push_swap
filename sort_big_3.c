/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:59:13 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/12 19:07:03 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra + rrb rotation
static void	ra_rot(t_data *dat, int a, int b)
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
	if (dat->b->num < dat->a->num && dat->a == dat->min)
		dat->min = dat->b;
	oper_select(dat, PUSH_A);
}

// rra + rb rotation
static void	rb_rot(t_data *dat, int a, int b)
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
	if (dat->b->num < dat->a->num && dat->a == dat->min)
		dat->min = dat->b;
	oper_select(dat, PUSH_A);
}

// rr rotation
static void	rr_rot(t_data *dat, int a, int b)
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
	if (dat->b->num < dat->a->num && dat->a == dat->min)
		dat->min = dat->b;
	oper_select(dat, PUSH_A);
}

// rrr rotation
static void	rrr_rot(t_data *dat, int a, int b)
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
	if (dat->b->num < dat->a->num && dat->a == dat->min)
		dat->min = dat->b;
	oper_select(dat, PUSH_A);
}

// Select whichever operation to perform based on the operation count stored in
// the array.
void	exec_oper(t_data *dat, int arr[5])
{
	if (arr[0] < arr[4] && arr[2] < arr[4])
		rr_rot(dat, arr[0], arr[2]);
	else if (arr[1] < arr[4] && arr[3] < arr[4])
		rrr_rot(dat, arr[1], arr[3]);
	else if (arr[0] + arr[3] == arr[4] - 1)
		ra_rot(dat, arr[0], arr[3]);
	else if (arr[1] + arr[2] == arr[4] - 1)
		rb_rot(dat, arr[1], arr[2]);
}
