#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_stack
{
    int	value;
	int	index;
	int	position;
	int	target_pos;
	int	cost_a;
	int	cost_b;
	struct s_stack *next;
}	t_stack;

void	op_sa(t_stack **stack_a);
void	op_sb(t_stack **stack_b);
void	op_ss(t_stack **stack_a, t_stack **stack_b);

void    op_ra(t_stack **stack_a);
void    op_rb(t_stack **stack_b);
void    op_rr(t_stack **stack_a, t_stack **stack_b);

void op_rra(t_stack **stack_a);
void op_rrb(t_stack **stack_b);
void op_rrr(t_stack **stack_a, t_stack **stack_b);

void    op_pa(t_stack **stack_a, t_stack **stack_b);
void    op_pb(t_stack **stack_a, t_stack **stack_b);

void	ft_putstr(char *str);
size_t	ft_strlen(const char *s);
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_second_to_last(t_stack *stack);
long int	ft_atoi(const char *str);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_new(int value);
void	free_stacks(t_stack **stack);
void	error(t_stack **stack_a, t_stack **stack_b);
int	stack_count(t_stack *stack);
int	abs_val(int nb);

long	input_checks(char *str);
int  duplicate_check(t_stack *stack);

void	fill_values(char *argv, t_stack **stack_a);
void	assign_index(t_stack *stack_a, int stack_size);

int	is_sorted(t_stack *stack);

void    sort_three(t_stack **stack_a);

void	keep_three(t_stack **stack_a, t_stack **stack_b);

int smallest_i_position(t_stack **stack);
void    assign_target_positions(t_stack **stack_a, t_stack **stack_b);

void    assign_cost(t_stack **stack_a, t_stack **stack_b);

void    find_cheapest(t_stack **stack_a, t_stack **stack_b);

void    reorder(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);

void    big_sort(t_stack **stack_a, t_stack **stack_b);

char	**ft_split(char const *s, char c);

#endif