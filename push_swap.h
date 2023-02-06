#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

typedef struct s_stack
{
    int	value;
	int	index;
	int	position;
	int	target_pos;
	int	moves_a;
	int	moves_b;
	struct s_stack *next;
}	t_stack;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;


static void swap(t_stack *stack);
void	op_sa(t_stack **stack_a);
void	op_sb(t_stack **stack_b);
void	op_ss(t_stack **stack_a, t_stack **stack_b);

void    rotate(t_stack **stack);
void    op_ra(t_stack **stack_a);
void    op_rb(t_stack **stack_b);
void    op_rr(t_stack **stack_a, t_stack **stack_b);

void    op_pa(t_stack **stack_a, t_stack **stack_b);
void    op_pb(t_stack **stack_b, t_stack **stack_a);

void	ft_putstr(char *str);
t_list	*ft_lstlast(t_list *lst);

#endif