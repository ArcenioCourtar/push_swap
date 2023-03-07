/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:40:42 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/07 15:02:27 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_data *dat)
{
	if (dat->a->num > dat->a->next->num)
		oper_select(dat, SWAP_A);
}

void	sort_three(t_data *dat)
{
	int	num[3];

	num[0] = dat->a->num;
	num[1] = dat->a->next->num;
	num[2] = dat->a->next->next->num;
	if (num[0] < num[1] && num[0] < num[2] && num[1] > num[2])
	{
		oper_select(dat, SWAP_A);
		oper_select(dat, ROT_A);
	}
	else if (num[0] > num[1] && num[0] < num[2])
		oper_select(dat, SWAP_A);
	else if (num[0] < num[1] && num[0] > num[2])
		oper_select(dat, RROT_A);
	else if (num[0] > num[1] && num[0] > num[2])
	{
		if (num[1] < num[2])
			oper_select(dat, ROT_A);
		else
		{
			oper_select(dat, SWAP_A);
			oper_select(dat, RROT_A);
		}
	}
}

static void	sort_five_helper(t_data *dat)
{
	t_dlist	*min;

	min = dat->a;
	while (dat->b != NULL)
	{
		if (dat->b->num < dat->a->num && dat->a == min)
		{
			oper_select(dat, PUSH_A);
			min = dat->a;
		}
		else if (dat->b->num < dat->a->num && dat->b->num > dat->a->prev->num)
			oper_select(dat, PUSH_A);
		else if (dat->b->num > dat->a->prev->num && dat->a == min)
			oper_select(dat, PUSH_A);
		else
		{
			rotate_calc(dat, min);
		}
	}
}

void	sort_five(t_data *dat, int len)
{
	while (len > 3)
	{
		oper_select(dat, PUSH_B);
		len--;
	}
	sort_three(dat);
	sort_five_helper(dat);
	if (!is_sorted(dat->a))
		rotate_calc(dat, NULL);
}
