SRCS = ft_isdigit.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstfind.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_strlen.c

OBJS = $(SRCS:.c=.o)

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

objs:
	cc -c $(CFLAGS) $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
