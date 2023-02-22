#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

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

static void    rotate(t_stack **stack);
void    op_ra(t_stack **stack_a);
void    op_rb(t_stack **stack_b);
void    op_rr(t_stack **stack_a, t_stack **stack_b);

static void    rev_rotate(t_stack **stack);
void op_rra(t_stack **stack_a);
void op_rrb(t_stack **stack_b);
void op_rrr(t_stack **stack_a, t_stack **stack_b);

void    op_pa(t_stack **stack_a, t_stack **stack_b);
void    op_pb(t_stack **stack_b, t_stack **stack_a);

void	ft_putstr(char *str);
t_stack	*stack_last(t_stack *stack);
long int	ft_atoi(const char *str);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_new(long int value);

t_stack	*fill_values(int argc, char **argv);
void	assign_index(t_stack *stack_a, int stack_size);

#endif