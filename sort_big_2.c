/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:42:59 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/12 17:36:18 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calc_low(int arr_tmp[5])
{
	arr_tmp[4] = arr_tmp[0] + arr_tmp[3] + 1;
	if (arr_tmp[4] > (arr_tmp[1] + arr_tmp[2]))
		arr_tmp[4] = arr_tmp[1] + arr_tmp[2] + 1;
	if (arr_tmp[0] > arr_tmp[2])
	{
		if (arr_tmp[4] > arr_tmp[0])
			arr_tmp[4] = arr_tmp[0] + 1;
	}
	else
	{
		if (arr_tmp[4] > arr_tmp[2])
			arr_tmp[4] = arr_tmp[2] + 1;
	}
	if (arr_tmp[1] > arr_tmp[3])
	{
		if (arr_tmp[4] > arr_tmp[1])
			arr_tmp[4] = arr_tmp[1] + 1;
	}
	else
	{
		if (arr_tmp[4] > arr_tmp[3])
			arr_tmp[4] = arr_tmp[3] + 1;
	}
}

static void	update_arr(int arr[5], int arr_tmp[5])
{
	arr[0] = arr_tmp[0];
	arr[1] = arr_tmp[1];
	arr[2] = arr_tmp[2];
	arr[3] = arr_tmp[3];
	arr[4] = arr_tmp[4];
}

static void	check_prev(t_data *dat, int i, t_dlist *prv, int arr[5])
{
	t_dlist	*tmpptr;
	int		arr_tmp[5];

	arr_tmp[4] = 0;
	arr_tmp[0] = 0;
	arr_tmp[2] = dlist_count(dat->b) - i;
	arr_tmp[3] = i;
	tmpptr = dat->a;
	while (!correct_loc(tmpptr, prv, dat->min))
	{
		arr_tmp[0]++;
		tmpptr = tmpptr->next;
	}
	if (arr_tmp[0] == 0)
		arr_tmp[1] = 0;
	else
		arr_tmp[1] = dlist_count(dat->a) - arr_tmp[1];
	calc_low((arr_tmp));
	if (arr[4] == 0 || arr[4] > arr_tmp[4])
		update_arr(arr, arr_tmp);
}

static void	check_next(t_data *dat, int i, t_dlist *nxt, int arr[5])
{
	t_dlist	*tmpptr;
	int		arr_tmp[5];

	arr_tmp[4] = 0;
	arr_tmp[0] = 0;
	arr_tmp[2] = i;
	if (i == 0)
		arr_tmp[3] = 0;
	else
		arr_tmp[3] = dlist_count(dat->b) - i;
	tmpptr = dat->a;
	while (!correct_loc(tmpptr, nxt, dat->min))
	{
		arr_tmp[0]++;
		tmpptr = tmpptr->next;
	}
	if (arr_tmp[0] == 0)
		arr_tmp[1] = 0;
	else
		arr_tmp[1] = dlist_count(dat->a) - arr_tmp[0];
	calc_low((arr_tmp));
	if (arr[4] == 0 || arr[4] > arr_tmp[4])
		update_arr(arr, arr_tmp);
}

// RA, RRA, RB, RRB, MIN
void	calc_fastest(t_data *dat, int arr[5])
{
	t_dlist	*nxt;
	t_dlist	*prv;
	int		i;
	int		len;

	i = 0;
	len = dlist_count(dat->b);
	nxt = dat->b;
	prv = dat->b;
	while (1)
	{
		check_next(dat, i, nxt, arr);
		if (i != 0)
			check_prev(dat, i, prv, arr);
		nxt = nxt->next;
		prv = prv->prev;
		i++;
		if (i >= arr[4] || i > len / 2)
			break ;
	}
}
