/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:16:58 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/07 15:02:05 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_dlist	*ptr_to_prev(t_dlist *trav)
{
	t_dlist	*ptr;

	ptr = trav;
	if (ptr->stkdown == NULL)
	{
		while (ptr->stkup != NULL)
			ptr = ptr->stkup;
		return (ptr);
	}
	while (ptr->stkdown != NULL)
		ptr = ptr->stkdown;
	ptr = ptr->stkprev;
	if (ptr == NULL)
		return (NULL);
	while (ptr->stkup != NULL)
		ptr = ptr->stkup;
	return (ptr);
}

static int	addto_stack(t_dlist **curr, t_dlist **trav)
{
	if ((*trav) == NULL)
		return (1);
	while ((*trav)->stkup != NULL)
		(*trav) = (*trav)->stkup;
	if ((*curr)->num < (*trav)->num)
	{
		(*trav)->stkup = (*curr);
		(*curr)->stkdown = (*trav);
		(*curr)->lisptr = ptr_to_prev(*curr);
		(*trav) = NULL;
		return (1);
	}
	while ((*trav)->stkdown != NULL)
		(*trav) = (*trav)->stkdown;
	return (0);
}

static void	new_stack(t_dlist **curr, t_dlist **trav)
{
	(*trav)->stknext = (*curr);
	(*curr)->stkprev = (*trav);
	(*curr)->lisptr = ptr_to_prev(*trav);
}

static void	mark_lis(t_dlist **a)
{
	t_dlist	*trav;

	trav = (*a);
	while ((trav)->stknext != NULL)
		(trav) = (trav)->stknext;
	while ((trav)->stkup != NULL)
		(trav) = (trav)->stkup;
	while ((trav) != NULL)
	{
		trav->lis = 1;
		(trav) = (trav)->lisptr;
	}
}

static void	create_stack(t_dlist *start, t_dlist *curr)
{
	t_dlist	*trav;

	while (curr != start)
	{
		trav = start;
		while (trav->stknext != NULL)
		{
			if (addto_stack(&curr, &trav))
				break ;
			trav = trav->stknext;
		}
		if (!addto_stack(&curr, &trav))
			new_stack(&curr, &trav);
		curr = curr->next;
	}
}

static int	longest_lis(t_dlist *start)
{
	static int	maxlen = 0;
	int			len;
	t_dlist		*trav;

	trav = start;
	len = 1;
	while (trav->stknext != NULL)
	{
		len++;
		trav = trav->stknext;
	}
	if (len > maxlen)
	{
		maxlen = len;
		return (1);
	}
	return (0);
}

static void	clearptrs(t_dlist **a)
{
	t_dlist	*pos;

	pos = (*a);
	while ((pos)->next != (*a))
	{
		(pos)->stknext = NULL;
		(pos)->stkprev = NULL;
		(pos)->stkup = NULL;
		(pos)->stkdown = NULL;
		(pos)->lisptr = NULL;
		(pos) = (pos)->next;
	}
	(pos)->stknext = NULL;
	(pos)->stkprev = NULL;
	(pos)->stkup = NULL;
	(pos)->stkdown = NULL;
	(pos)->lisptr = NULL;
}

void	lis(t_dlist **a)
{
	t_dlist	*start;
	t_dlist	*longest;

	start = (*a);
	while (1)
	{
		create_stack(start, start->next);
		if (longest_lis(start))
			longest = start;
		clearptrs(a);
		start = start->next;
		if (start == (*a))
			break ;
	}
	create_stack(longest, longest->next);
	mark_lis(&longest);
}
