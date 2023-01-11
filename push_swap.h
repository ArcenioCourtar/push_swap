/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:32:07 by acourtar          #+#    #+#             */
/*   Updated: 2023/01/11 15:42:26 by acourtar         ###   ########.fr       */
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
void	dlist_push(t_dlist *list, t_dlist *node);
void	dlist_pop(t_dlist **list);

void	instr_swap(t_dlist *list);
void	instr_rot(t_dlist **list);
void	instr_rrot(t_dlist **list);
void	instr_push(t_dlist **src, t_dlist **dest);

void	debug_list_disp(t_dlist *list);
void	debug_list_count(t_dlist *list);

#endif