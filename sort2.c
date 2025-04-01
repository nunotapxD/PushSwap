#include "push_swap.h"

void	push_chunk(t_stack *a, t_stack *b, int min_pivot, int max_pivot)
{
	int		i;
	int		size;
	int		pushed;
	t_node	*current;
	int		target;

	size = a->size;
	pushed = 0;
	target = 0;
	current = a->top;
	while (current && a->size > 3)
	{
		if (current->value >= min_pivot && current->value <= max_pivot)
			target++;
		current = current->next;
	}
	i = 0;
	while (i < size && pushed < target && a->size > 3)
	{
		if (a->top->value >= min_pivot && a->top->value <= max_pivot)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
		i++;
	}
}