#include "push_swap.h"

/*shifts down all elements of a stack (functions below for stack A, B or both) by 1. 
Last element becomes the first*/
static void    rev_rotate(t_stack **stack)
{
    t_stack *temp;
    t_stack *temp2;
    t_stack *last;
    t_stack *before_last;

    temp2 = NULL;
    last = stack_last(*stack);
    before_last = stack_second_to_last(*stack);
    temp = *stack;
    *stack = last;
    (*stack)->next = temp;
    temp2->next = NULL;
    before_last->next = NULL;
}

void op_rra(t_stack **stack_a)
{
    rev_rotate(stack_a);
    ft_putstr("rra\n");
}

void op_rrb(t_stack **stack_b)
{
    rev_rotate(stack_b);
    ft_putstr("rrb\n");
}

void op_rrr(t_stack **stack_a, t_stack **stack_b)
{
    rev_rotate(stack_a);
    rev_rotate(stack_b);
    ft_putstr("rrr\n");
}