/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 08:58:28 by mpeterso          #+#    #+#             */
/*   Updated: 2023/03/27 09:48:43 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*assigns a position to each element of the stack, starting with 0*/
static void	assign_position(t_stack **stack)
{
	t_stack	*temp;
	int		pos;

	temp = *stack;
	pos = 0;
	while (temp)
	{
		temp->position = pos;
		temp = temp->next;
		pos++;
	}
}

/*locates the position at which the smallest index in the stack can be found. 
Useful for shifting function at end of big_sort algorithm*/
int	smallest_i_position(t_stack **stack)
{
	t_stack	*temp;
	int		lowest_pos;
	int		lowest_i;

	temp = *stack;
	lowest_i = INT_MAX;
	assign_position(stack);
	lowest_pos = temp->position;
	while (temp)
	{
		if (temp->index < lowest_i)
		{
			lowest_i = temp->index;
			lowest_pos = temp->position;
		}
		temp = temp->next;
	}
	return (lowest_pos);
}

/*finds the best target position in stack_a for a given index 
of an element in stack_b*/
static int	find_target(t_stack **stack_a, int index_b,
int target_index, int target_pos)
{
	t_stack	*temp;

	temp = *stack_a;
	while (temp)
	{
		if (temp->index > index_b && temp->index < target_index)
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
		if (temp->index < target_index)
		{
			target_index = temp->index;
			target_pos = temp->position;
		}
		temp = temp->next;
	}
	return (target_pos);
}

/*assigns target positions to each element of stack_b*/
void	assign_target_positions(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		target_position;

	temp = *stack_b;
	assign_position(stack_a);
	assign_position(stack_b);
	target_position = 0;
	while (temp)
	{
		target_position = find_target(stack_a, temp->index,
				INT_MAX, target_position);
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