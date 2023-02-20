/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:16:58 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/20 17:43:04 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorting.h"

// t_dlist	*ptr_to_prev(t_dlist *trav)
// {
// 	t_dlist	*ptr;

// 	ptr = trav;
// 	while (ptr->stkdown != NULL)
// 		ptr = ptr->stkdown;
// 	if (ptr->stkprev == NULL)
// 	{
// 		ft_printf("prev: (null)\n");
// 		return (NULL);
// 	}
// 	ptr = ptr->stkprev;
// 	while (ptr->stkup != NULL)
// 		ptr = ptr->stkup;
// 	if (ptr == NULL)
// 		ft_printf("prev: (null)\n");
// 	else
// 		ft_printf("prev: %i\n", ptr->num);
// 	return (ptr);
// }

int	addto_stack(t_dlist **curr, t_dlist **trav)
{
	if ((*trav) == NULL)
		return (1);
	while ((*trav)->stkup != NULL)
		(*trav) = (*trav)->stkup;
	if ((*curr)->num < (*trav)->num)
	{
		(*trav)->stkup = (*curr);
		(*curr)->stkdown = (*trav);
		(*curr)->stack = (*trav)->stack;
		// (*curr)->listptr = ptr_to_prev(*trav);
		// ft_printf("num %i to stack %i ", (*curr)->num, (*trav)->stack);
		(*trav) = NULL;
		return (1);
	}
	while ((*trav)->stkdown != NULL)
		(*trav) = (*trav)->stkdown;
	return (0);
}

void	new_stack(t_dlist **curr, t_dlist **trav)
{
	(*trav)->stknext = (*curr);
	(*curr)->stkprev = (*trav);
	// ft_printf("num %i new stack %i ", (*curr)->num, (*curr)->stack + 1);
	// (*curr)->listptr = ptr_to_prev(*trav);
	(*curr)->stack = (*trav)->stack + 1;
}

void	mark_lis(t_dlist **a)
{
	t_dlist	*trav;

	trav = (*a);
	while ((trav)->stknext != NULL)
		(trav) = (trav)->stknext;
	while ((trav)->stkup != NULL)
		(trav) = (trav)->stkup;
	while ((trav) != NULL)
	{
		ft_printf(" %i", (trav)->num);
		(trav) = (trav)->listptr;
	}
}

void	lis(t_dlist **a)
{
	t_dlist	*curr;
	t_dlist	*trav;
	int		stack;

	stack = 1;
	curr = (*a)->next;
	while (curr != (*a))
	{
		trav = (*a);
		while (trav->stknext != NULL)
		{
			if (addto_stack(&curr, &trav))
				break ;
			trav = trav->stknext;
		}
		if (!addto_stack(&curr, &trav))
			new_stack(&curr, &trav);
		if (curr->stack > stack)
			stack = curr->stack;
		curr = curr->next;
	}
	ft_printf("longest sequence: %i\nnumbers:", stack);
	mark_lis(a);
}
