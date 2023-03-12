/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:16:58 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/12 18:40:27 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(t_dlist *start, t_dlist *curr);

// After the longest LIS has been found it marks all nodes that are part of
// the LIS so the sorting algorithm can use that information.
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

// Traverses the LIS and compares it to the previously found longest LIS.
// If the LIS for the current starting index is longer is returns 1.
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

// Set all ptrs back to NULL after going through the entire list for
// startig index a
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

// Generate the Longest Increasing Subsequence using patience sort.
// Saves the node at which the LIS is found and marks all of the LIS members
// at the end.
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
