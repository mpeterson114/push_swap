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


static void swap(t_stack *stack);
void	op_sa(t_stack **stack_a);
void	op_sb(t_stack **stack_b);
void	op_ss(t_stack **stack_a, t_stack **stack_b);

void	ft_putstr(char *str);

#endif