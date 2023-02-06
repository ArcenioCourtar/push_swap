/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:30:46 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/06 13:21:40 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug_list_disp(t_dlist *list)
{
	t_dlist	*start;

	if (list == NULL)
	{
		ft_printf("(null)\n\n");
		return ;
	}
	list = list->prev;
	start = list;
	while (list->prev != start)
	{
		ft_printf("%i \n", list->num);
		list = list->prev;
	}
	ft_printf("%i\n\n", list->num);
}

void	debug_list_count(t_dlist *list)
{
	t_dlist	*start;
	int		i;

	if (list == NULL)
	{
		ft_printf("List length: 0");
		return ;
	}
	i = 1;
	start = list;
	while (list->next != start)
	{
		i++;
		list = list->next;
	}
	ft_printf("List length: %i\n", i);
}
