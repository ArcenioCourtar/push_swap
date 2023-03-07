/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:24:15 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/07 15:26:57 by acourtar         ###   ########.fr       */
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

void	create_stack(t_dlist *start, t_dlist *curr)
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
