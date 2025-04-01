#include "push_swap.h"

int	ft_atoi_check(const char *str, int *error)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (!str[i])
	{
		*error = 1;
		return (0);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			*error = 1;
			return (0);
		}
		result = result * 10 + (str[i++] - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1 && result * sign < INT_MIN))
		{
			*error = 1;
			return (0);
		}
	}
	*error = 0;
	return ((int)(result * sign));
}