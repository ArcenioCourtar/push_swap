/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:29:11 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/08 18:08:21 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stepcount_tmp(int steptmp, int len);
void	ins_back(t_data **dat, t_dlist *shortptr, t_dlist **min);

static int	stepcounter(t_data *dat, t_dlist *curr, t_dlist *min)
{
	int		result;
	int		steptmp;
	int		len;
	t_dlist	*tmpptr;

	tmpptr = curr;
	len = dlist_count(dat->b);
	steptmp = 0;
	while (dat->b != tmpptr)
	{
		steptmp++;
		tmpptr = tmpptr->next;
	}
	result = stepcount_tmp(steptmp, len);
	steptmp = 0;
	tmpptr = dat->a;
	len = dlist_count(dat->a);
	while (!correct_loc(tmpptr, curr, min))
	{
		steptmp++;
		tmpptr = tmpptr->next;
	}
	result += stepcount_tmp(steptmp, len) + 1;
	return (result);
}

t_dlist	*sort_part(t_data *dat, t_dlist *min)
{
	t_dlist	*curr;
	t_dlist	*shortptr;
	int		low;
	int		steptmp;

	low = 0;
	curr = dat->b;
	while (1)
	{
		steptmp = stepcounter(dat, curr, min);
		if (low == 0 || steptmp < low)
		{
			low = steptmp;
			shortptr = curr;
		}
		curr = curr->next;
		if (curr == dat->b)
			break ;
	}
	return (shortptr);
}

void	sort(t_data **dat, t_dlist **min)
{
	t_dlist	*shortptr;

	while ((*dat)->b != NULL)
	{
		shortptr = sort_part((*dat), (*min));
		ins_back(dat, shortptr, min);
	}
}
