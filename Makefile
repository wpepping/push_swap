SRCS = ft_atol.c operations2.c operations.c push_swap.c stack_functions.c turk.c turk_utils2.c turk_utils.c utils.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

LIBFT_FOLDER = libft
LIBFT = libft.a

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	cc $(CFLAGS) $(OBJS) -L$(LIBFT_FOLDER) -lft -o $(NAME)

objs:
	cc -c $(CFLAGS) $(SRCS)

clean:
	$(MAKE) clean -C $(LIBFT_FOLDER)
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBFT_FOLDER)\$(LIBFT)
	rm -f $(NAME)

re: fclean all
