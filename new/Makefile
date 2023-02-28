CC			:=	cc
LIBFT		:=	libft/libft.a
CFLAGS		:=	-Wall -Werror -Wextra
NAME		:=	push_swap
OBJFILES	:=	main.o \
			data.o \
			debug_func.o \
			dlist.o \
			input_validation.o \
			operations.o \
			print_oper.o
HEADERFILES	:=	push_swap.h \
			print_oper.h

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

ft_%.o: ft_%.c $(HEADERFILES)
	$(CC) -c $(CFLAGS) -o $@ $<

$(LIBFT):
	$(MAKE) -C libft

fsanitize: $(NAME)
	$(CC) $(CFLAGS) $(OBJFILES) $(LIBFT) -fsanitize=address -o $(NAME)