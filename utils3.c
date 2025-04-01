#include "push_swap.h"

int	parse_input(t_stack *a, int argc, char **argv)
{
	int		error;
	int		value;
	t_node	*new;
	t_node	*last;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (0);
		value = ft_atoi_check(argv[i], &error);
		if (error || is_duplicate(a, value))
			return (0);
		new = new_node(value);
		if (!new)
			return (0);
		if (!a->top)
			a->top = new;
		else
		{
			last = a->top;
			while (last->next)
				last = last->next;
			last->next = new;
		}
		a->size++;
		i++;
	}
	return (1);
}