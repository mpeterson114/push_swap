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
		{
			write(2, "Error\n", 6);
			exit(1);
			//needs error function freeing both stacks
		}
		if (argc == 2)
			stack_a = stack_new(nb);
		else
			stack_add_back(&stack_a, stack_new(nb));
	}
	return (stack_a);
	//printf("%d\n", stack_a->value);
}

void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
	//printf("%d, ", highest->index);
	//printf("%d\n", highest->value);
}
