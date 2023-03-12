/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:29:23 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/12 18:12:46 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h> // exit
#include <unistd.h> // write
#include <limits.h> // boundary checking

// check if first character is + or -
static int	isplusmin(char c)
{
	return (c == '+' || c == '-');
}

// Checks if every argument is a number.
static int	is_nonum(int argc, char **argv)
{
	size_t	len;
	size_t	i;

	while (argc > 0)
	{
		len = ft_strlen(argv[argc]);
		i = 1;
		if (isplusmin(argv[argc][0]))
		{
			if (len == 1)
				return (1);
		}
		else if (!ft_isdigit(argv[argc][0]))
			return (1);
		while (i < len)
		{
			if (!ft_isdigit(argv[argc][i]))
				return (1);
			i++;
		}
		argc--;
	}
	return (0);
}

// Checks for duplicate numbers and int over/underflow
// Also checks if strlen of an arg isn't higher than 11.
// To avoid overflowing a long and getting back into int range or something.
static int	isdupe_isoverflow(int argc, char **argv)
{
	long	cmp;
	int		i;
	int		len;

	while (argc > 0)
	{
		len = ft_strlen(argv[argc]);
		if (len > 11)
			return (1);
		cmp = ft_atol(argv[argc]);
		if (cmp > INT_MAX || cmp < INT_MIN)
			return (1);
		i = argc - 1;
		while (i > 0)
		{
			if (cmp == ft_atol(argv[i]))
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
	if (is_nonum(argc - 1, argv) || isdupe_isoverflow(argc - 1, argv))
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_SUCCESS);
	}
	if (argc == 2)
		exit(EXIT_SUCCESS);
}
