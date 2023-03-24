#include "push_swap.h"

/*finds last element in linked list*/
t_stack	*stack_last(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/*finds second-to-last element in linked list*/
t_stack	*stack_second_to_last(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

/*creates new node*/
t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->position = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

/*adds new node to end of linked list*/
void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack *temp;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	temp = stack_last(*stack);
	temp->next = new;
}

/*used to free both stacks a and b*/
void	free_stacks(t_stack **stack)
{
	t_stack *temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

/*frees both stacks, writes "Error" message to standard error and 
exits the program*/
void	error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stacks(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stacks(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

/*finds number of elements in a stack*/
int	stack_count(t_stack *stack)
{
	int	count;

	count = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}