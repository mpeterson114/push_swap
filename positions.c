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

void    assign_position(t_stack *stack, int stack_size)
{
    int pos;
    t_stack *temp;

    stack_size = stack_count(stack);
    pos = 0;
    temp = stack;
    while (stack_size--)
    {
        while (temp)
        {
            temp->position = pos;
            pos++;
            temp = temp->next;
        }
    }
}

void    target_position(t_stack **stack_a, t_stack **stack_b)
{
    int target_pos;
    int highest_i;

    target_pos = 0;
    highest_i = highest_index(*stack_a);
    while (*stack_a && *stack_b)
    {
        if ((*stack_a)->index > (*stack_b)->index)
        {
            
            while ((*stack_b)->index < highest_i)
            {
                if ((*stack_a)->index == (*stack_b)->index + 1)
                {
                    target_pos = stack_a->position;
                    stack_b = stack_b->next;
                }
                else
                    *stack_a = (*stack_a)->next;    
            }
            if ((*stack_b)->index > highest_i)
                target_pos = smallest_i_position(*stack_a);
        }
        else
            stack_a = stack_a->next;
    }
    


}

int smallest_i_position(t_stack *stack, int lowest_pos)
{
    t_stack *temp;

    temp = stack;
    while (*temp)
    {
        if ((*temp)->index != 1)
            (*temp) = (*temp)->next;
        else if ((*temp)->index == 1)
        {
            target_pos = (*temp)->position;
            break ;
        }  
    } 
    return (lowest_pos); 






   /* int pos;
    int stack_size;

    pos = 0;
    stack_size = stack_count(*stack);
    while (stack_size--)
    {
        while (*stack && pos < stack_size)
        {  
            if ((*stack)->index == 1)
            {
                pos = (*stack)->position;
                break ;
            }
            else if ((*stack)->index != 1)
            {
                (*stack) = (*stack)->next;
                pos++;
            }    
        }
    }
    return(pos);
}

int main()
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;
    int position = 0;

    stack_a = (t_stack *)malloc(sizeof(t_stack));
    stack_b = (t_stack *)malloc(sizeof(t_stack));

    if (!stack_a)
        return 0;

    stack_a->value = 2;
    stack_a->index = 1;
    stack_a->position = 0;
    stack_a->next = (t_stack *)malloc(sizeof(t_stack));
    stack_a->next->value = 9;
    stack_a->next->index = 4;
    stack_a->next->position = 1;
    stack_a->next->next = (t_stack *)malloc(sizeof(t_stack));
    stack_a->next->next->value = 4;
    stack_a->next->next->index = 2;
    stack_a->next->next->position = 2;
    stack_a->next->next->next = (t_stack *)malloc(sizeof(t_stack));
    stack_a->next->next->next->value = 6;
    stack_a->next->next->next->index = 3;
    stack_a->next->next->next->position = 3;
    stack_a->next->next->next->next = NULL;

    smallest_index_pos(&stack_a);
    printf("%d ", position);
    while (stack_a)
    {
       
        printf("%d\n", (stack_a)->index);
        printf("%d ", (stack_b)->value);
        printf("%d\n", (stack_b)->index);
        stack_a = stack_a->next;
    }
    return 0;
}*/