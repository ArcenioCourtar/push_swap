/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:32:07 by acourtar          #+#    #+#             */
/*   Updated: 2023/01/10 14:29:00 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct dlist {
	int				num;
	struct dlist	*next;
	struct dlist	*prev;
}	t_dlist;

t_dlist	*dlist_new(int num);
void	dlist_push(t_dlist **list, t_dlist *node);

#endif