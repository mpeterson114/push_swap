#include "push_swap.h"

/*checks that argument is a number. '+' and '-' are accepted. If is a number returns 1, 
if not a number returns 0*/
static int  number_check(char *argv)
{
    int i;

	i = 0;
    if (is_sign(argv[i]) && argv[i + 1] != '\0')
        i++;
    while (argv[i] && is_digit(argv[i]))
        i++;
    if (!is_digit(argv[i]) && argv[i] != '\0')
        return (0);
    return (1);
}

/*checks for duplicates in arguments-if found returns 1, if no duplicates are found returns 0*/
static int  duplicate_check(char **argv)
{
    int i;
    int j;

	i = 1;
    while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && !strcmp(argv[i], argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*checks if argument is a zero. counts +0, -0, 0 as well as 000000 -0000 +000000 etc as zero values. 
Returns 1 if argument is a variation of zero, returns 0 if not zero value (e.g., 00004)*/
static int  zero_check(char *argv)
{
    int i;

	i = 0;
    if (is_sign(argv[i]))
        i++;
    while (argv[i] && argv[i] == '0')
        i++;
    if (argv[i] != '\0')
        return (0);
    return (1);
}

int	input_checks(char **argv)
{
	int	i;
	int	num_zeros;

	num_zeros = 0;
	i = 1;
	while (argv[i])
	{
		if (!number_check(argv[i]))
			return (0);
		num_zeros += zero_check(argv[i]);
		i++;
	}
	if (num_zeros > 1)
		return (0);
	if (duplicate_check(argv))
		return (0);
	return (1);
}