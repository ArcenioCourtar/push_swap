/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:12:38 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/20 14:24:46 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H
# include "push_swap.h"

void	sort_two(t_dlist **a);
void	sort_three(t_dlist **a);
void	sort_five(t_dlist **a, t_dlist **b, int len);
void	lis(t_dlist **a);

#endif