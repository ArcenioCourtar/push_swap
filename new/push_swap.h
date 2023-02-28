/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:50:27 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/28 15:03:22 by acourtar         ###   ########.fr       */
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
	struct dlist	*a;
	struct dlist	*b;
	struct dlist	*op;
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

// Checks if input is valid
// TODO: strlen check for long overflows? :)
void	valid_input(int argc, char **argv);

// sets up top level data struct;
t_data	*data_new(void);
// Initialize a new node of the linked list with value "num".
// The "prev" and "next" pointers both point back to itself.
t_dlist	*dlist_new(int num);
// add a node to the linked list
void	dlist_add(t_dlist **list, t_dlist *new);
// remove the first element of the node
void	dlist_pop(t_dlist **list);
// Display the number of node elements
int		dlist_count(t_dlist *list);
// view list;
void	dlist_view(t_dlist *list);


void	oper_select(t_data *dat, int mode);


// exit function
// TODO: proper freeing of nodes
void	exit_func(t_data **dat);

#endif