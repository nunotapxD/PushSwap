#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (b->size > 0)
	{
		tmp = b->top;
		b->top = tmp->next;
		tmp->next = a->top;
		a->top = tmp;
		a->size++;
		b->size--;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (a->size > 0)
	{
		tmp = a->top;
		a->top = tmp->next;
		tmp->next = b->top;
		b->top = tmp;
		a->size--;
		b->size++;
		write(1, "pb\n", 3);
	}
}

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