#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack->size > 1)
	{
		first = stack->top;
		last = stack->top;
		while (last->next)
			last = last->next;
		stack->top = first->next;
		first->next = NULL;
		last->next = first;
	}
}

void	ra(t_stack *a)
{
	if (a->size > 1)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack *b)
{
	if (b->size > 1)
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->size > 1 && b->size > 1)
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
	}
}