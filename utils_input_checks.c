#include "push_swap.h"

/*checks if input is an integer value*/
int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*checks if input is a sign ('+' or '-')*/
int is_sign(char c)
{
    if (c == '+' || c == '-')
        return (1);
    return (0);
}

