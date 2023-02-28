#include "push_swap.h"

/*writes character string to standard output*/
void	ft_putstr(char *str)
{
	int	i;
	
	i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

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
	while (stack && stack->next != NULL && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

/*converts character to int value; used to fill stack_a with 
command line arguments*/
long int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	long int	result;

	if (str == NULL)
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}	
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/*creates new node*/
t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->position = -1;
	new->target_pos = -1;
	new->moves_a = -1;
	new->moves_b = -1;
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
	if (!stack_a || !*stack_a)
		free_stacks(stack_a);
	if (!stack_b || !*stack_b)
		free_stacks(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

/*finds number of elements in a stack*/
int	stack_count(t_stack *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 1;
	while (stack->next != NULL)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}