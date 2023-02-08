/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:40:42 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/08 15:12:56 by acourtar         ###   ########.fr       */
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

void	sort_five(t_dlist **a, t_dlist **b, int len)
{
	while (len > 3)
	{
		oper_select(a, b, PUSH_B);
		len--;
	}
	sort_three(a);
	while ((*b) != NULL)
	{
		if ((*b)->num < (*a)->num && (*b)->num < (*a)->num)
			oper_select(a, b, PUSH_A);
		else if ((*b)->num > (*a)->num && (*b)->num > (*a)->prev->num)
		{
			oper_select(a, b, PUSH_A);
			oper_select(a, b, ROT_A);
		}
	}
}
