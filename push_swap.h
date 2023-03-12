/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:50:27 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/12 19:30:53 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

enum e_oper {
	SWAP_A,
	SWAP_B,
	SWAP_S,
	PUSH_A,
	PUSH_B,
	ROT_A,
	ROT_B,
	ROT_R,
	RROT_A,
	RROT_B,
	RROT_R
};

typedef struct data {
	struct dlist	*min;
	struct dlist	*a;
	struct dlist	*b;
}	t_data;

typedef struct dlist {
	int				num;
	struct dlist	*next;
	struct dlist	*prev;
	int				lis;
	struct dlist	*stknext;
	struct dlist	*stkprev;
	struct dlist	*stkup;
	struct dlist	*stkdown;
	struct dlist	*lisptr;
}	t_dlist;

void	valid_input(int argc, char **argv);
t_dlist	*dlist_new(int num);
void	dlist_add(t_dlist **list, t_dlist *new);
void	dlist_pop(t_dlist **list);
int		dlist_count(t_dlist *list);
void	oper_select(t_data *dat, int mode);
void	select_sort(t_data *dat);
int		is_sorted(t_dlist *a);
void	rotate_calc(t_data *dat, t_dlist *min);
int		correct_loc(t_dlist *a, t_dlist *b, t_dlist *min);

#endif