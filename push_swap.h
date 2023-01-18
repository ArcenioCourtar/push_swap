/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:32:07 by acourtar          #+#    #+#             */
/*   Updated: 2023/01/18 15:36:28 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# define SWAP_A 0
# define SWAP_B 1
# define SWAP_S 2
# define PUSH_A 3
# define PUSH_B 4
# define ROT_A 5
# define ROT_B 6
# define ROT_R 7
# define RROT_A 8
# define RROT_B 9
# define RROT_R 10

typedef struct dlist {
	int				num;
	struct dlist	*next;
	struct dlist	*prev;
}	t_dlist;

t_dlist	*dlist_new(int num);
void	dlist_push(t_dlist *list, t_dlist *node);
void	dlist_pop(t_dlist **list);

void	instr_select(t_dlist **list_a, t_dlist **list_b, int mode);
void	print_instr(int mode);
void	print_instr_push(int mode);

void	debug_list_disp(t_dlist *list);
void	debug_list_count(t_dlist *list);

#endif