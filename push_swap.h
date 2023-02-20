/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:32:07 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/20 15:34:45 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

// enum of all possible operations.
// ROT = FIRST elem becomes LAST
// RROT = LAST elem becomes FIRST
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

// Double liked list. Keep track of start/end by saving the starting point
typedef struct dlist {
	int				num;
	struct dlist	*next;
	struct dlist	*prev;
	int				stack;
	struct dlist	*stknext;
	struct dlist	*stkprev;
	struct dlist	*stkup;
	struct dlist	*stkdown;
	struct dlist	*listptr;
}	t_dlist;

// Check if the list of arguments passed is valid and can be used.
void	valid_input(int argc, char **argv);

// Initialize a new node of the linked list with value "num".
// The "prev" and "next" pointers both point back to itself.
t_dlist	*dlist_new(int num);
// add a node to the linked list
void	dlist_add(t_dlist **list, t_dlist *new);
// remove the first element of the node
void	dlist_pop(t_dlist **list);
// view the node elements
void	dlist_view(t_dlist *list);
// Display the number of node elements
int		dlist_count(t_dlist *list);
// Select sorting alg based on length of list
void	select_sort(t_dlist **a, t_dlist **b);
// Check if list in it's current state is sorted
int		is_sorted(t_dlist *a);

// Select the operation to be performed on the stacks.
// Using the #define directives in the "mode" field to select said operation.
// The functions for the operations themselves are static and thus
// unavailable to any function outside of this one.
void	oper_select(t_dlist **list_a, t_dlist **list_b, int mode);

#endif