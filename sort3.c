#include "push_swap.h"

static void	push_back_to_a(t_stack *a, t_stack *b)
{
    int		max_b;
    int		pos;

    while (b->size > 0)
    {
        max_b = get_max(b);
        pos = get_pos(b, max_b);
        if (pos <= b->size / 2)
        {
            while (b->top && b->top->value != max_b)
                rb(b);
        }
        else
        {
            while (b->top && b->top->value != max_b)
                rrb(b);
        }
        pa(a, b);
    }
}

void	sort_big(t_stack *a, t_stack *b)
{
    int		min_val;
    int		max_val;
    int		range;
    int		chunks;
    int		i;

    // Handle small cases directly
    if (a->size <= 5)
    {
        // For 4-5 elements, move smallest to B, sort A, then bring back
        while (a->size > 3)
        {
            int min = get_min(a);
            while (a->top->value != min)
                ra(a);
            pb(a, b);
        }
        sort_small(a);
        while (b->size > 0)
            pa(a, b);
        return;
    }

    min_val = get_min(a);
    max_val = get_max(a);
    range = max_val - min_val + 1;
    chunks = (a->size <= 100) ? 5 : 11;
    
    i = 0;
    while (i < chunks && a->size > 3)
    {
        push_chunk(a, b, min_val + (i * range / chunks),
            min_val + ((i + 1) * range / chunks) - 1);
        i++;
    }
    
    sort_small(a);
    push_back_to_a(a, b);
}