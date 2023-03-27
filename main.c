/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 08:58:24 by mpeterso          #+#    #+#             */
/*   Updated: 2023/03/27 08:58:25 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//checks that stack values are in order from smallest to largest
int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->next->value < stack->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
/*coordinating function for sorting algorithms depending on stack size. Evaluates based on stack sizes of
2, 3 or greater than 3 elements*/
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int	stack_size)
{
	if ((stack_size == 2) && !is_sorted(*stack_a))
		op_sa(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		big_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	int	i;

	if (argc < 2)
		return (0);
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (i < argc)
	{
		fill_values(argv[i], &stack_a);
		i++;
	}
	if (duplicate_check(stack_a))
		error(&stack_a, NULL);
	stack_size = stack_count(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	/*while (stack_a)
	{
		printf("%d ", stack_a->value);
		printf("%d\n", stack_a->index);
		printf ("\n");
		stack_a = stack_a->next;
	}*/
	free_stacks(&stack_a);
	free_stacks(&stack_b);
    return 0;
}