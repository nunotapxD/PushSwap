#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*prev;

	if (stack->size > 1)
	{
		last = stack->top;
		prev = NULL;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = stack->top;
		stack->top = last;
	}
}

void	rra(t_stack *a)
{
	if (a->size > 1)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack *b)
{
	if (b->size > 1)
	{
		reverse_rotate(b);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->size > 1 && b->size > 1)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		write(1, "rrr\n", 4);
	}
}