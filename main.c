/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:28:50 by acourtar          #+#    #+#             */
/*   Updated: 2023/01/10 18:07:50 by acourtar         ###   ########.fr       */
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

void	display_list(t_dlist *list)
{
	t_dlist	*startlist;

	list = list->prev;
	startlist = list;
	while (list->prev != startlist)
	{
		ft_printf("%i \n", list->num);
		list = list->prev;
	}
	ft_printf("%i\n\n", list->num);
}

int	main(int argc, char **argv)
{
	t_dlist	*numlist;

	numlist = fill_list(argc - 1, argv);
	display_list(numlist);
	instr_rot(&numlist);
	display_list(numlist);
	instr_rrot(&numlist);
	display_list(numlist);
	instr_swap(numlist);
	display_list(numlist);
}

// ft_printf("n: %i, p: %p, cur: %p, nxt: %p\n", numlist->num, numlist->prev, numlist, numlist->next);