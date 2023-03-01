/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:52:35 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/01 13:09:30 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorting.h"

static int	correct_loc(t_dlist *a, t_dlist *b, t_dlist *min)
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

static void	rotate_exec(t_data *dat, int steps, int len)
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
}

void	rotate_calc(t_data *dat, t_dlist *min)
{
	t_dlist	*ptr;
	int		steps;
	int		len;

	steps = 0;
	ptr = dat->a;
	len = dlist_count(dat->a);
	while (!correct_loc(ptr, dat->b, min))
	{
		steps++;
		ptr = ptr->next;
	}
	rotate_exec(dat, steps, len);
}