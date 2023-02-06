/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:42:46 by acourtar          #+#    #+#             */
/*   Updated: 2023/02/06 16:47:39 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_OPER_H
# define PRINT_OPER_H

// Additional header file, created because these functions serve no
// purpose besides adding additional functionality to the
// operation functions in operations.c.
// If it wasn't for 42norm compliance I'd put these function inside of
// operations.c and also make them static.

// Print the performed operation in STDOUT
void	print_oper(int mode);
// Print the performed push operation in STDOUT. Space issues. :(
void	print_oper_push(int mode);

#endif