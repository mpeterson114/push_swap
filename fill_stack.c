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
}

