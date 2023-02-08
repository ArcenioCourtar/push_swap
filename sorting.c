/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:49:49 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/08 15:14:41 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorting.h"

int	is_sorted(t_dlist *a)
{
	t_dlist	*start;
	int		num;

	start = a;
	num = a->num;
	a = a->next;
	while (a != start)
	{
		if (num > a->num)
			return (0);
		num = a->num;
		a = a->next;
	}
	ft_printf("Sorted!");
	return (1);
}

void	select_sort(t_dlist **a, t_dlist **b)
{
	int	len;

	len = dlist_count((*a));
	if (len == 2)
		sort_two(a);
	else if (len == 3)
		sort_three(a);
	else if (len < 6)
		sort_five(a, b, len);
}
