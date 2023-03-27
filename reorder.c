/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 08:58:36 by mpeterso          #+#    #+#             */
/*   Updated: 2023/03/27 08:58:37 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*while both cost_a & cost_b are negative, reverse rotates both stacks until either cost_a or cost_b reaches 0*/
static void rev_rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
    while (*cost_a < 0 && *cost_b < 0)
    {
        (*cost_a)++;
        (*cost_b)++;
        op_rrr(stack_a, stack_b);
    }
}
/*while both cost_a & cost_b are higher than 0, rotates both stacks until either cost_a or cost_b reaches 0*/
static void rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
    while (*cost_a > 0 && *cost_b > 0)
    {
        (*cost_a)--;
        (*cost_b)--;
        op_rr(stack_a, stack_b);
    }  
}
/*bring cost_a value to 0 using rotate (if > 0) or reverse rotate (if < 0)*/
static void a_only(t_stack **stack_a, int *cost_a)
{
    while (*cost_a)
    {
        if (*cost_a > 0)
        {
            op_ra(stack_a);
            (*cost_a)--;
        } 
        else if (*cost_a < 0)
        {
            op_rra(stack_a);
            (*cost_a)++;
        } 
    } 
}
/*bring cost_b value to 0 using rotate (if > 0) or reverse rotate (if < 0)*/
static void b_only(t_stack **stack_b, int *cost_b)
{
    while (*cost_b)
    {
        if (*cost_b > 0)
        {
            op_rb(stack_b);
            (*cost_b)--;
        }
        else if (*cost_b < 0)
        {
            op_rrb(stack_b);
            (*cost_b)++;
        } 
    }
}
/*once cheapest option is found in 'find_cheapest', lines up stack_a and stack_b to appropriate positions using costs
in order to push that element from stack_b to stack_a*/
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

