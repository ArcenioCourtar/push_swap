/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:14:47 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/12 19:13:07 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis(t_dlist **a);
void	calc_fastest(t_data *dat, int arr[5]);
void	exec_oper(t_data *dat, int arr[5]);

// push everything not marked as part of the lis to b
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

// This array (and everything like it in the following files) has this format:
// arr[0]: ra, [1]: rra, [2]: rb, [3]: rrb, [4]: lowest # of moves
// First calculates the fastest set of moves to move somthing from b to a.
// Then executes the moves stored in the array, loop until stack b is empty.
static void	ins_back(t_data *dat)
{
	int		arr[5];

	while (dat->b != NULL)
	{
		arr[4] = 0;
		calc_fastest(dat, arr);
		exec_oper(dat, arr);
	}
}

// Sorting alg used for more than 5 elements.
// First calculate the Longest Increasing Subsequence,
// Push everything not part of the LIS to b
// Insert everything back into a and get the starting value on top.
void	sort_big(t_data *dat)
{
	lis(&(dat->a));
	initial_push(dat);
	ins_back(dat);
	while (!is_sorted(dat->a))
		rotate_calc(dat, NULL);
}
