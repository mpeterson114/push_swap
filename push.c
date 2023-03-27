/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 08:58:33 by mpeterso          #+#    #+#             */
/*   Updated: 2023/03/27 09:33:15 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (*src == NULL)
		return ;
	temp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = temp;
}

/*pushes element at top of stack B to the top of stack A*/
void	op_pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

/*pushes element at top of stack A to the top of stack B*/
void	op_pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}

/*int main(void)
{
    //testing with t_stack struct modified in .h file 
	//to only include value, index & next
	t_stack *first_a = NULL;
	t_stack *second_a = NULL;
	t_stack *third_a = NULL;

    t_stack *first_b = NULL;
	t_stack *second_b = NULL;
	t_stack *third_b = NULL;

	first_a = (t_stack *)malloc(sizeof(t_stack));
	second_a = (t_stack *)malloc(sizeof(t_stack));
	third_a = (t_stack *)malloc(sizeof(t_stack));

    first_b = (t_stack *)malloc(sizeof(t_stack));
	second_b = (t_stack *)malloc(sizeof(t_stack));
	third_b = (t_stack *)malloc(sizeof(t_stack));

	first_a->value = 2;
	first_a->index = 1;
	first_a->next = second_a;

    second_a->value = 4;
	second_a->index = 2;
	second_a->next = third_a;

	third_a->value = 6;
	third_a->index = 3;
	third_a->next = NULL;

    first_b->value = 22;
	first_b->index = 1;
	first_b->next = second_b;

    second_b->value = 44;
	second_b->index = 2;
	second_b->next = third_b;

	third_b->value = 66;
	third_b->index = 3;
	third_b->next = NULL;

	op_pb(&first_b, &first_a);
	printf("%d\n", first_b->value);
	printf("%d\n", first_b->index);
    printf("%d\n", first_a->value);
	printf("%d\n", first_a->index);
	printf("%d\n", first_b->next->value);
	//printf("%d\n", stack->next->index);
	return 0;
}*/