/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:32:07 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/06 16:57:20 by acourtar         ###   ########.fr       */
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

// Double liked list. Keep track of start/end by saving the starting point
typedef struct dlist {
	int				num;
	struct dlist	*next;
	struct dlist	*prev;
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
void	dlist_count(t_dlist *list);

// Select the operation to be performed on the stacks.
// Using the #define directives in the "mode" field to select said operation.
// The functions for the operations themselves are static and thus
// unavailable to any function outside of this one.
void	oper_select(t_dlist **list_a, t_dlist **list_b, int mode);

#endif