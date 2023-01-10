/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:28:50 by acourtar          #+#    #+#             */
/*   Updated: 2023/01/10 16:13:20 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// ALLOWED: read, write, malloc, free, exit

t_dlist	*fill_list(int argc, char **argv)
{
	t_dlist	*begin;
	t_dlist	*current;

	begin = dlist_new(ft_atoi(argv[argc]));
	argc--;
	while (argc > 0)
	{
		current = dlist_new(ft_atoi(argv[argc]));
		dlist_push(&begin, current);
		argc--;
	}
	return (begin);
}

int	main(int argc, char **argv)
{
	t_dlist	*numlist;
	t_dlist	*startlist;

	numlist = fill_list(argc - 1, argv);
	startlist = numlist;
	while (numlist->next != NULL)
	{
		ft_printf("n: %i, p: %p, cur: %p, nxt: %p\n", numlist->num, numlist->prev, numlist, numlist->next);
		numlist = numlist->next;
	}
	ft_printf("n: %i, p: %p, cur: %p, nxt: %p\n", numlist->num, numlist->prev, numlist, numlist->next);
	return (0);
}
