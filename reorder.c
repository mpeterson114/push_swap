#include "push_swap.h"

static void rev_rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
    while (*cost_a < 0 && *cost_b < 0)
        op_rrr(stack_a, stack_b);
        (*cost_a)++;
        (*cost_b)++;
}

static void rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
    while (*cost_a > 0 && *cost_b > 0)
        op_rr(stack_a, stack_b);
        (*cost_a)--;
        (*cost_b)--;
}

static void a_only(t_stack **stack_a, int *cost_a)
{
    while (*cost_a > 0)
        op_ra(stack_a);
        (*cost_a)--;
    while (*cost_a < 0)
        op_rra(stack_a);
        (*cost_a)++;
}

static void b_only(t_stack **stack_b, int *cost_b)
{
    while (*cost_b > 0)
        op_rb(stack_b);
        (*cost_b)--;
    while (*cost_b < 0)
        op_rrb(stack_b);
        (*cost_b)++;
}

void    reorder(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
    if (cost_a < 0 && cost_b < 0)
        rev_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
    else if (cost_a > 0 && cost_b > 0)
        rotate_both(stack_a, stack_b, &cost_a, &cost_b);
    a_only(stack_a, &cost_a);
    b_only(stack_b, &cost_b);
    op_pa(stack_a, stack_b);
}

