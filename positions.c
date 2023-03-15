#include "push_swap.h"

void    assign_position(t_stack **stack)
{
    int pos;
    t_stack *temp;

    pos = 0;
    temp = *stack;
    while (temp)
    {
        temp->position = pos;
        temp = temp->next;
        pos++;
    }
}


int smallest_i_position(t_stack *stack)
{
    t_stack *temp;
    int lowest_pos;

    temp = stack;
    assign_position(&stack);
    lowest_pos = temp->position;
    while (temp)
    {
        if (temp->index != 1)
            temp = temp->next;
        else if (temp->index == 1)
        {
            lowest_pos = temp->position;
            break ;
        }
    } 
    return (lowest_pos); 
}

int    find_targ_pos(t_stack **stack_a, t_stack **stack_b, int target_pos)
{
    int target_index;
    t_stack *temp;

    temp = *stack_a;
    target_index = INT_MAX;
    while (temp)
    {
        if (temp->index > (*stack_b)->index && temp->index < target_index)
        {
            target_index = temp->index;
            target_pos = temp->position;
        }
        temp = temp->next; 
    }
    if (target_index != INT_MAX)
        return (target_pos);
    temp = *stack_a;
    while (temp)
    {
        if (temp->index < (*stack_b)->index && temp->index < target_index)
        {
            target_index = temp->index;
            target_pos = temp->position;
        }
        temp = temp->next;
    }
    return (target_pos);
}

void    assign_target_positions(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp;
    int target_position;

    temp = *stack_b;
    assign_position(stack_a);
    assign_position(stack_b);
    target_position = 0;
    while (temp)
    {
        target_position = find_targ_pos(stack_a, stack_b, target_position);
        temp->target_pos = target_position;
        temp = temp->next;
    }
    
}

/*int main()
{
    t_stack *stack_a = NULL;
    t_stack *temp = NULL;
    t_stack *stack_b = NULL;
    int target_position;

    stack_a = (t_stack *)malloc(sizeof(t_stack));
    stack_b = (t_stack *)malloc(sizeof(t_stack));
    if (!stack_a || !stack_b)
        return 0;
    temp = stack_b;
    target_position = temp->target_pos;
    

    stack_a->value = 9;
    stack_a->index = 4;
    stack_a->position = 0;
    stack_a->next = (t_stack *)malloc(sizeof(t_stack));
    stack_a->next->value = 6;
    stack_a->next->index = 3;
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

    assign_target_positions(&stack_a, &stack_b, target_position)
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