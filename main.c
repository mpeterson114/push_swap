#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (ac < 2)
		return (0);
	//if (!is_correct_input(av))
	//	exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_values(ac, av);
	stack_size = ac;
	assign_index(stack_a, stack_size + 1);
    return 0;}