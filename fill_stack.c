#include "push_swap.h"

t_stack	*fill_values(int argc, char **argv)
{
	long int    nb;
	int	i;
	t_stack *stack_a;

	stack_a = NULL;
	i = 1; 
	nb = 0;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			error(&stack_a, NULL);
		if (i == 1)
			stack_a = stack_new((int)nb);
		else
			stack_add_back(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack *temp;
	t_stack *highest;
	int value;

	while (stack_size-- > 0)
	{
		value = INT_MIN;
		temp = stack_a;
		highest = NULL;
		while (temp)
		{
			if (temp->value == INT_MIN && temp->index == 0)
				temp->index = 1;
			else if (temp->value > value && temp->index == 0)
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
