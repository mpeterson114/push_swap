#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

typedef struct s_stack
{
    int	value;
	int	index;
	int	position;
	int	target_pos;
	int	moves_a;
	int	moves_b;
	struct s_stack *next;
}	t_stack;




#endif