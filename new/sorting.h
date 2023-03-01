/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:59:59 by acourtar          #+#    #+#             */
/*   Updated: 2023/03/01 17:37:03 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

void	sort_two(t_data *dat);
void	sort_three(t_data *dat);
void	sort_five(t_data *dat, int len);
void	sort_big(t_data *dat);
void	rotate_calc(t_data *dat, t_dlist *min);
int		correct_loc(t_dlist *a, t_dlist *b, t_dlist *min);
void	lis(t_dlist **a);

#endif