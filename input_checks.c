#include "push_swap.h"

/*ensures that all arguments are valid number values; allows for + and -. If a valid number value returns 1, if not returns 0 */
long	input_checks(char *str)
{
	int i;

	i = 0;
    if ((str[i] == '-' || str[i] == '+') && (ft_strlen(str) > 1))
        i++;
    while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
    return (1);
}

/*checks for duplicates in arguments-if found returns 1, if no duplicates are found returns 0*/
int  duplicate_check(t_stack *stack)
{
    t_stack *tmp;
    t_stack *tmp2;

	tmp = stack;
    while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}