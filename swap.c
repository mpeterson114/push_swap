#include "push_swap.h"

static void swap(t_stack *stack)
{
   int  temp;
   
   if (stack == NULL || stack->next == NULL)
   		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	op_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

void	op_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

void	op_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}

/*int main(void)
{
	t_stack *stack;

	stack->value = 2;
	stack->next->value = 5; 
	stack->index = 1;
	stack->next->index = 2;

	swap(stack);
	printf("%d\n", stack->value);
	printf("%d\n", stack->index);
	//printf("%d\n", stack->next->value);
	//printf("%d\n", stack->next->index);
	return 0;
}*/