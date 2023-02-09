#include "push_swap.h"

static void    rev_rotate(t_stack **stack)
{
    t_stack *temp;
    t_stack *last;
    t_stack *before_last;

    last = ft_lstlast(*stack);
    temp = *stack;
    while (before_last->next->next != NULL)
        before_last = before_last->next;
    *stack = last;
    (*stack)->next = temp;
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