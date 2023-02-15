/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:33:20 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/15 15:33:55 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	rotation_calc(t_dlist **a, t_dlist **b, t_dlist *max)
// {
// 	int		steps;
// 	int		len;
// 	t_dlist	*current;

// 	steps = 0;
// 	current = (*a);
// 	len = dlist_count(*a);
// 	if ((*b)->num > max->num)
// 	{
// 		while (current->prev->num != max->num)
// 		{
// 			steps++;
// 			current = current->next;
// 		}
// 	}
// 	if (steps < len / 2)
// 	{
// 		while (steps > 0)
// 		{
// 			oper_select(a, NULL, ROT_A);
// 			steps--;
// 		}
// 	}	
// 	else
// 	{
// 		while (steps < len)
// 		{
// 			oper_select(a, NULL, RROT_A);
// 			steps++;
// 		}
// 	}
// }
