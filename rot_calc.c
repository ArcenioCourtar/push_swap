/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:52:35 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/22 13:26:12 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorting.h"

static void	rotate_exec(t_dlist **list, int steps, int len)
{
	if (steps > len / 2)
	{
		while (steps < len)
		{
			oper_select(list, NULL, RROT_A);
			steps++;
		}
	}
	else
	{
		while (steps > 0)
		{
			oper_select(list, NULL, ROT_A);
			steps--;
		}
	}
}

void	rotate_calc(t_dlist **a, t_dlist **b, t_dlist *min)
{
	t_dlist	*ptr;
	int		steps;
	int		len;

	steps = 0;
	ptr = (*a);
	len = dlist_count((*a));
	while (!correct_loc(ptr, (*b), min))
	{
		steps++;
		ptr = ptr->next;
	}
	rotate_exec(a, steps, len);
}

int	correct_loc(t_dlist *a, t_dlist *b, t_dlist *min)
{
	if (b == NULL && is_sorted(a))
		return (1);
	else if (min != NULL)
	{
		if (a->prev->num < b->num && b->num < a->num)
			return (1);
		else if (a->prev->num < b->num && a == min)
			return (1);
		else if (b->num < a->num && a == min)
			return (1);
	}
	return (0);
}
