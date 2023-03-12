/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:49:55 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/12 18:52:19 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

// Allocate memory for the struct that holds the addresses of the stacks.
static t_data	*data_new(void)
{
	t_data	*new;

	new = ft_calloc(1, sizeof(t_data));
	if (new == NULL)
		return (NULL);
	return (new);
}

// Exit function that frees all allocated memory and exits the program if
// allocation fails. (err == 1)
// Otherwise, frees the allocated memory but does not exit(); (err == 0) 
void	exit_func(t_data **dat, int err)
{
	while ((*dat)->a != NULL)
		dlist_pop(&((*dat)->a));
	free(*dat);
	if (err == 1)
		exit(EXIT_SUCCESS);
}

// fills list with all the numbers given as input.
static t_data	*fill_list(int argc, char **argv)
{	
	t_data	*new;
	t_dlist	*current;

	new = data_new();
	if (new == NULL)
		exit_func(&new, 1);
	new->a = dlist_new(ft_atoi(argv[argc]));
	if (new->a == NULL)
		exit_func(&new, 1);
	argc--;
	while (argc > 0)
	{
		current = dlist_new(ft_atoi(argv[argc]));
		if (current == NULL)
			exit_func(&new, 1);
		dlist_add(&(new->a), current);
		argc--;
	}
	return (new);
}

// Check if the input is valid, if it's not, exit(), otherwise continue.
// Allocate memory for a doubly linked list that stores all the numbers.
// Preemptively check if the list is already sorted, if not, sort.
// Select sorting alg based on # of numbers.
int	main(int argc, char **argv)
{
	t_data	*dat;

	valid_input(argc, argv);
	dat = fill_list(argc - 1, argv);
	if (!is_sorted(dat->a))
		select_sort(dat);
	exit_func(&dat, 0);
	return (0);
}
