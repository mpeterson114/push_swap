#include "push_swap.h"

void    keep_three(t_stack **stack_a, t_stack **stack_b)
{
    int stack_a_count;
    int highest;
    int i;

    stack_a_count = stack_count(*stack_a);
    highest = stack_a_count;
    i = 1;
    while (*stack_a && i <= highest && stack_a_count >= 3)
    {
        if ((*stack_a)->index <= (highest / 2))
        {
            op_pb(stack_b, stack_a);
            stack_a_count--;
        } 
        else if ((*stack_a)->index > (highest / 2))
            op_ra(stack_a);
        i++;     
    }
    while (stack_a_count > 3)
    {
        op_pb(stack_b, stack_a);
        stack_a_count--;
    }
    sort_three(stack_a);
}

/*int main ()
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;

    stack_a = (t_stack *)malloc(sizeof(t_stack));
    stack_b = (t_stack *)malloc(sizeof(t_stack));

    if (!stack_a)
        return 0;

    stack_a->value = 2;
    stack_a->index = 1;
    stack_a->next = (t_stack *)malloc(sizeof(t_stack));
    stack_a->next->value = 9;
    stack_a->next->index = 4;
    stack_a->next->next = (t_stack *)malloc(sizeof(t_stack));
    stack_a->next->next->value = 4;
    stack_a->next->next->index = 2;
    stack_a->next->next->next = (t_stack *)malloc(sizeof(t_stack));
    stack_a->next->next->next->value = 6;
    stack_a->next->next->next->index = 3;
    stack_a->next->next->next->next = NULL;

    keep_three(&stack_a, &stack_b);
    while (stack_a && stack_b)
    {
        printf("%d ", (stack_a)->value);
        printf("%d\n", (stack_a)->index);
        printf("%d ", (stack_b)->value);
        printf("%d\n", (stack_b)->index);
        stack_a = stack_a->next;
    }
    return 0;
}*/
