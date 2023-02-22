#include "push_swap.h"

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

t_stack	*stack_last(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

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
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' || 
		str[i] == '\t' || str[i] == '\f' || str[i] == '\r')
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

t_stack	*stack_new(long int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->position = 0;
	new->target_pos = 0;
	new->moves_a = 0;
	new->moves_b = 0;
	new->next = NULL;
	return (new);
}

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

