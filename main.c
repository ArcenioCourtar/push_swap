/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:28:50 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/08 15:13:59 by acourtar         ###   ########.fr       */
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
	t_dlist	*a;
	t_dlist	*b;

	valid_input(argc, argv);
	a = fill_list(argc - 1, argv);
	b = NULL;
	if (is_sorted(a))
		return (0);
	select_sort(&a, &b);
	return (0);
}
