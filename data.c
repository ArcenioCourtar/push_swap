/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:05:06 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/28 14:27:53 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_data	*data_new(void)
{
	t_data	*new;

	new = ft_calloc(1, sizeof(t_data));
	if (new == NULL)
		return (NULL);
	return (new);
}

void	exit_func(t_data **dat)
{
	while ((*dat)->a != NULL)
		dlist_pop(&((*dat)->a));
	while ((*dat)->b != NULL)
		dlist_pop(&((*dat)->b));
	while ((*dat)->op != NULL)
		dlist_pop(&((*dat)->op));
	free(*dat);
	exit(EXIT_SUCCESS);
}
