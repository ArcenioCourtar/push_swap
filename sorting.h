/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:12:38 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/21 17:08:18 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H
# include "push_swap.h"

void	sort_two(t_dlist **a);
void	sort_three(t_dlist **a);
void	sort_five(t_dlist **a, t_dlist **b, int len);
void	sort_big(t_dlist **a, t_dlist **b);
int		correct_loc(t_dlist *a, t_dlist *b, t_dlist *min);
void	rotate_calc(t_dlist **a, t_dlist **b, t_dlist *min);
void	lis(t_dlist **a);

#endif