/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:28:50 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/07 12:13:08 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
// ALLOWED: read, write, malloc, free, exit

t_dlist	*fill_list(int argc, char **argv)
{
	t_dlist	*start;
	t_dlist	*current;

	start = dlist_new(ft_atoi(argv[argc]));
	argc--;
	while (argc > 0)
	{
		current = dlist_new(ft_atoi(argv[argc]));
		dlist_add((&start), current);
		argc--;
	}
	return (start);
}

int	main(int argc, char **argv)
{
	t_dlist	*list_a;
	t_dlist	*list_b;

	valid_input(argc, argv);
	list_a = fill_list(argc - 1, argv);
	list_b = NULL;

	dlist_view(list_a);
	dlist_view(list_b);
	oper_select(&list_a, &list_b, PUSH_B);
	dlist_view(list_a);
	dlist_view(list_b);
	oper_select(&list_a, &list_b, PUSH_B);
	dlist_view(list_a);
	dlist_view(list_b);
	oper_select(&list_a, &list_b, PUSH_B);
	dlist_view(list_a);
	dlist_view(list_b);
	oper_select(&list_a, &list_b, PUSH_B);
	dlist_view(list_a);
	dlist_view(list_b);
	oper_select(&list_a, &list_b, PUSH_A);
	dlist_view(list_a);
	dlist_view(list_b);
	oper_select(&list_a, &list_b, PUSH_A);
	dlist_view(list_a);
	dlist_view(list_b);
	oper_select(&list_a, &list_b, PUSH_A);
	dlist_view(list_a);
	dlist_view(list_b);
	oper_select(&list_a, &list_b, PUSH_A);
	dlist_view(list_a);
	dlist_view(list_b);
}
