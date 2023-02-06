/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:00:35 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/06 15:30:11 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // write, STDOUT_FILENO
#include "push_swap.h"

void	print_oper(int mode)
{
	static int	twice = 0;

	if (mode == SWAP_S && twice == 1)
		write(STDOUT_FILENO, "ss\n", 3);
	else if (mode == ROT_R && twice == 1)
		write(STDOUT_FILENO, "rr\n", 3);
	else if (mode == RROT_R && twice == 1)
		write(STDOUT_FILENO, "rrr\n", 4);
	else if (mode == SWAP_A)
		write(STDOUT_FILENO, "sa\n", 3);
	else if (mode == SWAP_B)
		write(STDOUT_FILENO, "sb\n", 3);
	else if (mode == ROT_A)
		write(STDOUT_FILENO, "ra\n", 3);
	else if (mode == ROT_B)
		write(STDOUT_FILENO, "rb\n", 3);
	else if (mode == RROT_A)
		write(STDOUT_FILENO, "rra\n", 4);
	else if (mode == RROT_B)
		write(STDOUT_FILENO, "rrb\n", 4);
	if ((mode == SWAP_S || mode == ROT_R || mode == RROT_R) && twice == 0)
		twice = 1;
	else
		twice = 0;
}

void	print_oper_push(int mode)
{
	if (mode == PUSH_A)
		write(STDOUT_FILENO, "pa\n", 3);
	else
		write(STDOUT_FILENO, "pb\n", 3);
}
