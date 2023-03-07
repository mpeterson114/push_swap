NAME = push_swap

HDRS = push_swap.h
SRCS = utils.c \
	swap.c \
	push.c \
	rotate.c \
	rev_rotate.c \
	fill_stack.c \
	input_checks.c \
	utils_input_checks.c \
	sort_three.c \
	big_sort.c \
	positions.c \

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBC = ar rc
REMOVE = rm -f

OBJS = $(SRCS:.c=.o)

%o: %c
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

clean: 
	$(REMOVE) $(OBJS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re

