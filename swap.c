#include "push_swap.h"

/*swaps first two elements in a stack (functions below for stack A, B or both)*/
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
	//testing with t_stack struct modified in .h file 
	//to only include value, index & next
	t_stack *stack_1 = NULL;
	t_stack *stack_2 = NULL;
	t_stack *stack_3 = NULL;

	stack_1 = (t_stack *)malloc(sizeof(t_stack));
	stack_2 = (t_stack *)malloc(sizeof(t_stack));
	stack_3 = (t_stack *)malloc(sizeof(t_stack));

	stack_1->value = 2;
	stack_1->index = 1;
	stack_1->next = stack_2;

	stack_2->value = 4;
	stack_2->index = 2;
	stack_2->next = stack_3;

	stack_3->value = 6;
	stack_3->index = 3;
	stack_3->next = NULL;

	op_sa(&stack_1);
	printf("%d\n", stack_1->value);
	printf("%d\n", stack_1->index);
	printf("%d\n", stack_2->value);
	printf("%d\n", stack_2->index);
	printf("%d\n", stack_2->next->value);
	printf("%d\n", stack_2->next->index);
	return 0;
}*/