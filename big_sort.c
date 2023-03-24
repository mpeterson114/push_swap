#include "push_swap.h"
//push all elements to stack_b aside from 3 that remain in stack_a
void    keep_three(t_stack **stack_a, t_stack **stack_b)
{
    int stack_a_count;
    int pushed;
    int i;

    stack_a_count = stack_count(*stack_a);
    pushed = 0;
    i = 0;
    //stack_a_count value remains constant throughout fxn, even if elements are pushed to B
    while (stack_a_count > 6 && i < stack_a_count && pushed < stack_a_count / 2)
    {
        if ((*stack_a)->index <= stack_a_count / 2)
        {
            op_pb(stack_a, stack_b);
            pushed++;
        } 
        else
            op_ra(stack_a);
        i++;     
    }
    while ((stack_a_count - pushed) > 3)
    {
        op_pb(stack_a, stack_b);
        pushed++;
    }
}
/*once all elements have been sorted and returned to stack_a, shifts stack_a until lowest value is
at the top*/
static void    shift_stack_a(t_stack **stack_a)
{
    int stack_size;
    int smallest_pos;

    stack_size = stack_count(*stack_a);
    smallest_pos = smallest_i_position(stack_a);
    if (smallest_pos > stack_size / 2)
    {
        while (smallest_pos < stack_size)
        {
            op_rra(stack_a);
            smallest_pos++;
        }
    }    
    else
    {
        while (smallest_pos > 0)
        {
            op_ra(stack_a);
            smallest_pos--;
        }    
    }      
}
/*sorting algorithm for stack larger than 3 elements*/
void    big_sort(t_stack **stack_a, t_stack **stack_b)
{
    keep_three(stack_a, stack_b);
    sort_three(stack_a);
    while (*stack_b)
    {
        assign_target_positions(stack_a, stack_b);
        assign_cost(stack_a, stack_b);
        find_cheapest(stack_a, stack_b);
    }
    if (!is_sorted(*stack_a))
        shift_stack_a(stack_a);
}
