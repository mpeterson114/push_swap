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
void    op_pb(t_stack **stack_b, t_stack **stack_a);

void	ft_putstr(char *str);
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_second_to_last(t_stack *stack);
long int	ft_atoi(const char *str);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_new(int value);
void	free_stacks(t_stack **stack);
void	error(t_stack **stack_a, t_stack **stack_b);
int	stack_count(t_stack *stack);
int	abs_val(int nb);

int	is_digit(char c);
int is_sign(char c);
int	strcmp(const char *s1, const char *s2);
int	input_checks(char **argv);

t_stack	*fill_values(int argc, char **argv);
void	assign_index(t_stack *stack_a, int stack_size);

int	is_sorted(t_stack *stack);

void    sort_three(t_stack **stack_a);

//int highest_index(t_stack *stack);
void	keep_three(t_stack **stack_a, t_stack **stack_b);

void    assign_position(t_stack **stack);
int smallest_i_position(t_stack *stack);
int    find_targ_pos(t_stack **stack_a, t_stack **stack_b, int target_pos);
void    assign_target_positions(t_stack **stack_a, t_stack **stack_b);

void    assign_cost(t_stack **stack_a, t_stack **stack_b);

void    find_cheapest(t_stack **stack_a, t_stack **stack_b);

void    reorder(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);

void    big_sort(t_stack **stack_a, t_stack **stack_b);

void    shift_stack_a(t_stack **stack_a);

//void print_list(t_stack **head);      ----->practice

#endif