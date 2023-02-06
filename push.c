#include "push_swap.h"

void    op_pa(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp; 

    if (!*stack_b)
		return ;
	temp = (*stack_b)->next;
    (*stack_b)->next = *stack_a; 
	*stack_a = *stack_b;
    *stack_b = temp; 
    ft_putstr("pa\n");
}

void    op_pb(t_stack **stack_b, t_stack **stack_a)
{
    t_stack *temp; 

    if (!*stack_a)
		return ;
	temp = (*stack_a)->next;
    (*stack_a)->next = *stack_b; 
	*stack_b = *stack_a;
    *stack_a = temp; 
    ft_putstr("pb\n");
}