/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:00:35 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/07 13:02:20 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // write, STDOUT_FILENO
#include "push_swap.h"

static void	print_oper_helper(int mode)
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

void	print_oper(t_dlist *oper)
{
	t_dlist	*start;

	if (oper == NULL)
		return ;
	start = oper;
	while (start != oper->next)
	{
		print_oper_helper(oper->num);
		oper = oper->next;
	}
	print_oper_helper(oper->num);
}

void	oper_add(t_data *dat, int mode)
{
	t_dlist	*add;

	if (dat->op == NULL)
	{
		dat->op = dlist_new(mode);
		if (dat->op == NULL)
			exit_func(&dat);
	}
	else
	{
		add = dlist_new(mode);
		if (add == NULL)
			exit_func(&dat);
		dlist_add_oper(&(dat->op), add);
	}
}
