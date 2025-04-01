#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size >= 2)
	{
		first = stack->top;
		second = first->next;
		first->next = second->next;
		second->next = first;
		stack->top = second;
	}
}

void	sa(t_stack *a)
{
	if (a->size >= 2)
	{
		swap(a);
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack *b)
{
	if (b->size >= 2)
	{
		swap(b);
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	if (a->size >= 2 && b->size >= 2)
	{
		swap(a);
		swap(b);
		write(1, "ss\n", 3);
	}
}