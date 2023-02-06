#include "push_swap.h"

static void    rotate(t_stack **stack)
{
    t_stack *temp;
    t_stack *end;

    temp = *stack;
    *stack = (*stack)->next;
    end = ft_lstlast(*stack);
    temp->next = NULL;
    end->next = temp;
}

void    op_ra(t_stack **stack_a)
{
    rotate(stack_a);
    ft_putstr("ra\n");
}

void    op_rb(t_stack **stack_b)
{
    rotate(stack_b);
    ft_putstr("rb\n");
}

void    op_rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    ft_putstr("rr\n");
}
