#include "push_swap.h"

static int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->next->value < stack->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int	stack_size)
{
	if (stack_size == 2 && !is_sorted(stack_a))
		op_sa;
	else if (stack_size == 3)
		sort_3(stack_a);

}



int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc < 2)
		return (0);
	if (!input_checks(argv))
		error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_values(argc, argv);
	stack_size = stack_count(stack_a);
	assign_index(stack_a, stack_size + 1);
	while (stack_a)
	{
		printf("%d ", stack_a->value);
		printf("%d\n", stack_a->index);
		stack_a = stack_a->next;
	}
	//free(&stack_a);
	//free(&stack_b);
    return 0;
}