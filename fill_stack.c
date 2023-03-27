/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 08:58:19 by mpeterso          #+#    #+#             */
/*   Updated: 2023/03/27 08:58:20 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Takes input (argv) as a string, splits it into an array of strings, checks 
 if each string is valid according to input parameters and converts it to an 
 integer. Adds it as a new element to the stack_a.*/
void	fill_values(char *argv, t_stack **stack_a)
{
	char **arguments;
	long int    nb;
	int	i;

	arguments = ft_split(argv, ' ');
	i = 0; 
	while (arguments[i])
	{
		if (input_checks(arguments[i]))
		{
			nb = ft_atoi(arguments[i]);
			if (nb > INT_MAX || nb < INT_MIN)
				error(stack_a, NULL);
			stack_add_back(stack_a, stack_new(nb));
		}
		else
			error(NULL, NULL);
		free(arguments[i]);
		i++;
	}
	free(arguments);
}

/*assigns an index to each stack element based on value. facilitates comparison 
and ordering of stack elements during sorting as comparing 
actual values may be more complicated if not adjacent*/
void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack *temp;
	t_stack *highest;
	int value;

	while (--stack_size > 0)
	{
		temp = stack_a;
		highest = NULL;
		value = INT_MIN;
		while (temp)
		{
			if (temp->value == INT_MIN && temp->index == 0)
				temp->index = 1;
			if (temp->value > value && temp->index == 0)
			{
				value = temp->value;
				highest = temp;
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
