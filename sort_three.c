#include "push_swap.h"
int highest_index(t_stack *stack)
{
    int index;

    index = 0;
    while (stack)
    {
        stack = stack->next;
        index++;
    }
    return (index);
}

/*checks first to see if already sorted. 
-If 3rd index is in 1st position, either needs ra or ra + sa
-If 3rd index is in 2nd position, either needs rra or rra + sa
-Will enter into final 'if' only if still not sorted 
(only case would be indices remaining in [2] [1] [3] order)*/
void    sort_three(t_stack **stack_a)
{
    int highest = highest_index(*stack_a);
    if (is_sorted(*stack_a))
        return ;
    if ((*stack_a)->index == highest)
        op_ra(stack_a);
    else if ((*stack_a)->next->index == highest)
        op_rra(stack_a);
    if ((*stack_a)->next->index < (*stack_a)->index)
        op_sa(stack_a);
    return ;
}
