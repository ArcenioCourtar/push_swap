/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:29:23 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/07 12:06:02 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h> // exit
#include <unistd.h> // write

// static int	are_numbers()
// {
// }

// static int	bound_check()
// {
// }

// checks for duplicate numbers
static int	check_duplicates(int argc, char **argv)
{
	int	comparing;
	int	i;

	while (argc > 0)
	{
		comparing = ft_atoi(argv[argc]);
		i = argc - 1;
		while (i > 0)
		{
			if (comparing == ft_atoi(argv[i]))
				return (1);
			i--;
		}
		argc--;
	}
	return (0);
}

// Check if arguments passed to push_swap are legitimate
void	valid_input(int argc, char **argv)
{
	if (argc == 1)
		exit(EXIT_SUCCESS);
	if (check_duplicates(argc - 1, argv))
	{
		write(STDOUT_FILENO, "Error\n", 6);
		exit(EXIT_SUCCESS);
	}
}
