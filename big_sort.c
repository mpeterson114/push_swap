#include "push_swap.h"

int highest_index(t_stack *stack)
{
    int index;

    if (!stack)
        return (0);
    index = 1;
    while (stack != NULL)
    {
        stack = stack->next;
        index++;
    }
    return (index); 
}

void    keep_three(t_stack **stack_a, t_stack **stack_b)
{
    int stack_a_count;
    int highest;

    highest = highest_index(*stack_a);
    stack_a_count = stack_count(*stack_a); //???-while loop to continue until only 3 elements left in stack_a
    while (*stack_a)
    if ((*stack_a)->index < (highest / 2))
}