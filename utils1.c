#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	while (stack->top)
	{
		tmp = stack->top;
		stack->top = tmp->next;
		free(tmp);
	}
	stack->size = 0;
}

int	is_sorted(t_stack *a)
{
	t_node	*current;

	if (!a->top || a->size == 1)
		return (1);
	current = a->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_duplicate(t_stack *a, int value)
{
	t_node	*current;

	current = a->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}