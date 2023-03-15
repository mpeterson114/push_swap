#include "push_swap.h"
static int highest_index(t_stack *stack)
{
    int index;

    index = stack->index;
    while (stack)
    {
        if (stack->index > index)
            index = stack->index;
        stack = stack->next;
    }
    return (index);
}

/*checks first to see if already sorted. 
-If 3rd index is in 1st position, either needs ra or ra + sa
-If 3rd index is in 2nd position, either needs rra or rra + sa
-Will enter into final 'if' only if still not sorted 
(only case would be indices remaining in [2] [1] [3] order)*/
void    sort_three(t_stack **stack)
{
    int highest;
    
    if (is_sorted(*stack))
        return ;
    highest = highest_index(*stack);
    if ((*stack)->index == highest)
        op_ra(stack);
    else if ((*stack)->next->index == highest)
        op_rra(stack);
    if ((*stack)->next->index < (*stack)->index)
        op_sa(stack);
}
