/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:42:59 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/12 17:03:15 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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