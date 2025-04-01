#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->size <= 1 || is_sorted(a))
		return;
	if (a->size <= 3)
		sort_small(a);
	else
		sort_big(a, b);
}

void	sort_small(t_stack *a)
{
	int	top;
	int	middle;
	int	bottom;

	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
		return;
	}
	top = a->top->value;
	middle = a->top->next->value;
	bottom = a->top->next->next->value;
	if (top > middle && middle > bottom)
	{
		sa(a);
		rra(a);
	}
	else if (top > middle && top > bottom)
		ra(a);
	else if (top > middle)
		sa(a);
	else if (top < middle && middle > bottom && top < bottom)
	{
		sa(a);
		ra(a);
	}
	else if (top < middle && middle > bottom)
		rra(a);
}