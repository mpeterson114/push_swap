#include "push_swap.h"

int b_cost(t_stack **stack_b)
{
    int stack_b_size;
    int cost_b;
    t_stack *temp;

    stack_b_size = stack_count(stack_b);
    cost_b = 0;
    temp = *stack_b;
    while (temp)
    {
        if (temp->position < stack_b_size / 2)
        {
            while (temp->position != 0)
            {
                op_rb;
                cost_b++;
            }
        }
        else
        {
            while (temp->position != 0)
            {
                op_rrb;
                cost_b++;
            }
            cost_b *= -1;  
        }
        temp = temp->next; 
    }
    return (cost_b);
}

int main()
{
    //t_stack *stack_a = NULL;
    t_stack *temp = NULL;
    t_stack *stack_b = NULL;
    int cost_b;

    //stack_a = (t_stack *)malloc(sizeof(t_stack));
    stack_b = (t_stack *)malloc(sizeof(t_stack));
    if (!stack_a || !stack_b)
        return 0;
    temp = stack_b;
    cost_b = b_cost(&stack_b);
    
    stack_b->position = 0;
    stack_b->cost_b = 0;
    stack_b->next = (t_stack *)malloc(sizeof(t_stack));
    stack_b->next->position = 1;
    stack_b->next->cost_b = ;
    stack_a->next->position = 1;
    stack_a->next->next = (t_stack *)malloc(sizeof(t_stack));
    stack_a->next->next->value = 4;
    stack_a->next->next->index = 2;
    stack_a->next->next->position = 2;
    stack_a->next->next->next = (t_stack *)malloc(sizeof(t_stack));
    stack_a->next->next->next->value = 2;
    stack_a->next->next->next->index = 1;
    stack_a->next->next->next->position = 3;
    stack_a->next->next->next->next = NULL;

    assign_target_positions(&stack_a, &stack_b, target_position);
    printf("%d ", smallest_i_position(&stack_a, position));
    while (stack_a)
    {
       
        printf("%d\n", (stack_a)->index);
        printf("%d ", (stack_b)->value);
        printf("%d\n", (stack_b)->index);
        stack_a = stack_a->next;
    }
    return 0;
}