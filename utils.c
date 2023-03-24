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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return(i);
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

int	abs_val(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}