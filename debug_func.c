/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:22:31 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/15 18:30:59 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

// View list elements in order.
void	dlist_view(t_dlist *list)
{
	t_dlist	*start;

	if (list == NULL)
	{
		write(STDOUT_FILENO, "(null)\n\n", 8);
		return ;
	}
	start = list;
	while (start != list->next)
	{
		list = list->next;
	}
}
