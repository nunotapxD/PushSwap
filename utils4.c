#include "push_swap.h"

int	get_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	get_pos(t_stack *stack, int value)
{
	t_node	*current;
	int		pos;

	pos = 0;
	current = stack->top;
	while (current && current->value != value)
	{
		pos++;
		current = current->next;
	}
	return (pos);
}