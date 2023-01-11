/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:28:50 by acourtar          #+#    #+#             */
/*   Updated: 2023/01/11 15:04:32 by acourtar         ###   ########.fr       */
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
		dlist_push(start, current);
		argc--;
	}
	return (start);
}

void	valid_input(int argc)
{
	if (argc == 0)
		exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_dlist	*list_a;
	t_dlist	*list_b;

	valid_input(argc - 1);
	list_a = fill_list(argc - 1, argv);
	list_b = NULL;
	debug_list_disp(list_a);
	debug_list_disp(list_b);
	instr_push(&list_a, &list_b);
	debug_list_disp(list_a);
	debug_list_disp(list_b);
	instr_push(&list_a, &list_b);
	debug_list_disp(list_a);
	debug_list_disp(list_b);
	instr_push(&list_a, &list_b);
	debug_list_disp(list_a);
	debug_list_disp(list_b);
}
