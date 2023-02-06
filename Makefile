CC			:= cc
LIBFT		:= libft/libft.a
CFLAGS		:= -Wall -Werror -Wextra
NAME		:= push_swap
OBJFILES	:= main.o \
			dlist.o \
			operations.o \
			print_oper.o \
			input_validation.o
HEADERFILES	:= push_swap.h \
			print_oper.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJFILES)
	cc $(CFLAGS) $(OBJFILES) $(LIBFT) -o $(NAME)

re: fclean all

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJFILES)

fclean:
	$(MAKE) fclean -C libft
	rm -f $(OBJFILES) $(NAME)

ft_%.o: ft_%.c $(HEADERFILES)
	$(CC) -c $(CFLAGS) -o $@ $<

$(LIBFT):
	$(MAKE) -C libft

fsanitize: $(NAME)
	cc $(CFLAGS) $(OBJFILES) $(LIBFT) -fsanitize=address -o $(NAME)