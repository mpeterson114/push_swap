/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 08:58:42 by mpeterso          #+#    #+#             */
/*   Updated: 2023/03/27 09:03:20 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*shifts up all elements of a stack (functions below for 
stack A, B or both) by 1. First element becomes the last*/
static void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*end;

	temp = *stack;
	*stack = (*stack)->next;
	end = stack_last(*stack);
	temp->next = NULL;
	end->next = temp;
}

void	op_ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

void	op_rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

void	op_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
