SRCS = ft_atol.c operations2.c operations.c stack_functions.c turk.c turk_utils2.c turk_utils.c utils.c

OBJS = $(SRCS:.c=.o)

NAME = libpush_swap.a

LIBFT_FOLDER = libft
LIBFT = libft.a

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_FOLDER)/$(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT_FOLDER)/$(LIBFT):
	$(MAKE) -C $(LIBFT_FOLDER)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(MAKE) clean -C $(LIBFT_FOLDER)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_FOLDER)
	rm -f $(NAME)

re: fclean all
