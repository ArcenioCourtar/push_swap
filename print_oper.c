/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:00:35 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/12 19:03:16 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // write, STDOUT_FILENO
#include "push_swap.h"

// It prints the operations. :)
void	print_oper(int mode)
{
	if (mode == SWAP_A)
		write(STDOUT_FILENO, "sa\n", 3);
	else if (mode == SWAP_B)
		write(STDOUT_FILENO, "sb\n", 3);
	else if (mode == SWAP_S)
		write(STDOUT_FILENO, "ss\n", 3);
	else if (mode == PUSH_A)
		write(STDOUT_FILENO, "pa\n", 3);
	else if (mode == PUSH_B)
		write(STDOUT_FILENO, "pb\n", 3);
	else if (mode == ROT_A)
		write(STDOUT_FILENO, "ra\n", 3);
	else if (mode == ROT_B)
		write(STDOUT_FILENO, "rb\n", 3);
	else if (mode == ROT_R)
		write(STDOUT_FILENO, "rr\n", 3);
	else if (mode == RROT_A)
		write(STDOUT_FILENO, "rra\n", 4);
	else if (mode == RROT_B)
		write(STDOUT_FILENO, "rrb\n", 4);
	else if (mode == RROT_R)
		write(STDOUT_FILENO, "rrr\n", 4);
}
