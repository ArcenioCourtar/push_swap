/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:49:55 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/28 17:39:52 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*fill_list(int argc, char **argv)
{	
	t_data	*new;
	t_dlist	*current;

	new = data_new();
	if (new == NULL)
		exit_func(&new);
	new->a = dlist_new(ft_atoi(argv[argc]));
	if (new->a == NULL)
		exit_func(&new);
	argc--;
	while (argc > 0)
	{
		current = dlist_new(ft_atoi(argv[argc]));
		if (current == NULL)
			exit_func(&new);
		dlist_add(&(new->a), current);
		argc--;
	}
	return (new);
}

int	main(int argc, char **argv)
{
	t_data	*dat;

	valid_input(argc, argv);
	dat = fill_list(argc - 1, argv);
	oper_select(dat, SWAP_A);
	oper_select(dat, SWAP_A);
	oper_select(dat, ROT_A);
	oper_select(dat, RROT_A);
	oper_select(dat, PUSH_B);
	oper_select(dat, PUSH_B);
	oper_select(dat, ROT_B);
	print_oper(dat->op);
}
