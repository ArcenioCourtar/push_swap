# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 16:43:02 by acourtar          #+#    #+#              #
#    Updated: 2023/03/12 18:26:31 by acourtar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:=	cc
LIBFT		:=	libft/libft.a
CFLAGS		:=	-Wall -Werror -Wextra
NAME		:=	push_swap
OBJFILES	:=	main.o \
			dlist.o \
			input_validation.o \
			operations.o \
			operations_2.o \
			print_oper.o \
			sorting.o \
			sort_small.o \
			rot_calc.o \
			sort_big.o \
			sort_big_2.o \
			sort_big_3.o \
			lis.o \
			lis_2.o
HEADERFILE	:=	push_swap.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) $(LIBFT) -o $(NAME)

re: fclean all

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJFILES)

fclean:
	$(MAKE) fclean -C libft
	rm -f $(OBJFILES) $(NAME)

ft_%.o: ft_%.c $(HEADERFILE)
	$(CC) -c $(CFLAGS) -o $@ $<

$(LIBFT):
	$(MAKE) -C libft

fsanitize: $(NAME)
	$(CC) $(CFLAGS) $(OBJFILES) $(LIBFT) -fsanitize=address -o $(NAME)