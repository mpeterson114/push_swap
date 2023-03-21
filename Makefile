NAME = push_swap

BLUE =			\033[0;94m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m

INCLUDE = push_swap.h
SRCS = main.c \
	utils.c \
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
	cost.c \
	reorder.c \
	ft_split.c \

CC = gcc
CFLAGS = -Wall -Werror -Wextra
REMOVE = rm -f

OBJS = $(SRCS:.c=.o)

%o: %c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\n$(GREEN) Objects and executables created successfully"

all: $(NAME)

clean: 
	$(REMOVE) $(OBJS)
	@echo "\n$(YELLOW) Objects deleted successfully"

fclean: clean
	$(REMOVE) $(NAME)
	@echo "\n$(BLUE)Objects and executables deleted successfully"

re: fclean all

.PHONY: all clean fclean re

