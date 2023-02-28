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

/*compares two strings by their ascii values. If strings are identical returns 0, 
otherwise returns a non-zero number*/
int	strcmp(const char *s1, const char *s2)
{
	int i;
    int j;

	i = 0;
    j = 0;
    if (s1[i] == '+')
    {
        if (s2[j] != '+')
            i++;
    }
    else
    {
        if (s2[j] == '+')
            j++;
    }
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
        j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
