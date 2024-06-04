SRCS = push_swap.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap

CHECKER_FOLDER = push_swap_checker
CHECKER_SRCS = $(CHECKER_FOLDER)/checker.c $(CHECKER_FOLDER)/checker_utils.c
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)
CHECKER_NAME = checker

LIB_FOLDER = libpush_swap
LIB_NAME = libpush_swap.a
LIB_COMPILE = push_swap

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIB_FOLDER)
	cc $(CFLAGS) $(OBJS) -L$(LIB_FOLDER) -l$(LIB_COMPILE) -o $(NAME)

objs:
	cc -c $(CFLAGS) $(SRCS)

checker: $(CHECKER_OBJS)
	$(MAKE) -C $(LIB_FOLDER)
	cc $(CFLAGS) $(CHECKER_OBJS) -L$(LIB_FOLDER) -l$(LIB_COMPILE) -o $(CHECKER_NAME)

checker_objs:
	cc -c $(CFLAGS) $(CHECKER_SRCS)

clean:
	$(MAKE) clean -C $(LIB_FOLDER)
	rm -f $(OBJS)
	rm -f $(CHECKER_OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIB_FOLDER)
	rm -f $(NAME)
	rm -f $(CHECKER_NAME)

re: fclean all
