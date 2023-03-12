/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:40:42 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/12 19:28:18 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// If the first number is higher than the second, swap em. :)
void	sort_two(t_data *dat)
{
	if (dat->a->num > dat->a->next->num)
		oper_select(dat, SWAP_A);
}

// there are six possible permutations for 3 different numbers, and each can be
// done in at most two moves.
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

// Figures out where the top number in b needs to be inside of a, then moves.
static void	sort_five_helper(t_data *dat)
{
	dat->min = dat->a;
	while (dat->b != NULL)
	{
		if (dat->b->num < dat->a->num && dat->a == dat->min)
		{
			oper_select(dat, PUSH_A);
			dat->min = dat->a;
		}
		else if (dat->b->num < dat->a->num && dat->b->num > dat->a->prev->num)
			oper_select(dat, PUSH_A);
		else if (dat->b->num > dat->a->prev->num && dat->a == dat->min)
			oper_select(dat, PUSH_A);
		else
		{
			rotate_calc(dat, dat->min);
		}
	}
}

// For the sorting of five (and four!) numbers, I first push numbers to b
// until I have only three numbers left in a.
// Then I just perform the hardcoed solution for 3 numbers, followed by
// inserting the other numbers back in with the helper function.
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
