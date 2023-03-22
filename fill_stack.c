#include "push_swap.h"

/*fills stack A with command line arguments entered. argv[i] char value 
is converted to stack value int nb using atoi. nb value cannot exceed INT_MIN or INT_MAX. 
A new node is created with nb as its value*/
void	fill_values(char *argv, t_stack **stack_a)
{
	char **arguments;
	long int    nb;
	int	i;

	arguments = ft_split(argv, ' ');
	i = 0; 
	while (arguments[i] != NULL)
	{
		if (input_checks(arguments[i]))
		{
			nb = ft_atoi(arguments[i]);
			if (nb > INT_MAX || nb < INT_MIN)
				error(stack_a, NULL);
			else
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
