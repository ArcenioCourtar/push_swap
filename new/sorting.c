/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:44:42 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/01 13:18:48 by acourtar         ###   ########.fr       */
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
	return (1);
}

void	select_sort(t_data *dat)
{
	int	len;

	len = dlist_count(dat->a);
	if (len == 2)
		sort_two(dat);
	else if (len == 3)
		sort_three(dat);
	else if (len < 6)
		sort_five(dat, len);
	else
		sort_big(dat);
}
