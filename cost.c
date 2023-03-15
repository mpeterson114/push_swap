#include "push_swap.h"

void    assign_cost(t_stack **stack_a, t_stack **stack_b)
{
    int size_a;
    int size_b;
    t_stack *temp_a;
    t_stack *temp_b;

    size_a = stack_count(*stack_a);
    size_b = stack_count(*stack_b);
    temp_a = *stack_a;
    temp_b = *stack_b;
    while (temp_b)
    {
        temp_b->cost_b = temp_b->position;
        if (temp_b->position > size_b / 2)
            temp_b->cost_b = (size_b - temp_b->position) * -1;
        temp_b->cost_a = temp_b->target_pos;
        if (temp_b->target_pos > size_a / 2)
            temp_b->cost_a = (size_a - temp_b->target_pos) * -1;
        temp_b = temp_b->next; 
    }
}

void    find_cheapest(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp;
    int cost_a;
    int cost_b;
    int cheapest;

    temp = *stack_b;
    cheapest = INT_MAX;
    while (temp)
    {   
        if (abs_val(temp->cost_a) + abs_val(temp->cost_b) < abs_val(cheapest))
        {
            cheapest = abs_val(temp->cost_a) + abs_val(temp->cost_b);
            cost_a = temp->cost_a;
            cost_b = temp->cost_b;
        }    
        temp = temp->next;
    }
    reorder(stack_a, stack_b, cost_a, cost_b);
}

/*int main()
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
}*/