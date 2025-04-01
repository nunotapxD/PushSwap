#include "push_swap.h"

void	push_chunk(t_stack *a, t_stack *b, int min_pivot, int max_pivot)
{
    int		i;
    int		original_size;
    int		pushed;
    int		rotations;

    original_size = a->size;
    pushed = 0;
    rotations = 0;
    
    // Push elements in range and track rotations
    i = 0;
    while (i < original_size && a->size > 3)
    {
        if (a->top->value >= min_pivot && a->top->value <= max_pivot)
        {
            pb(a, b);
            pushed++;
        }
        else
        {
            ra(a);
            rotations++;
        }
        i++;
    }

    // Restore stack A's order by undoing rotations
    i = 0;
    while (i < rotations && rotations < original_size / 2)
    {
        rra(a);
        i++;
    }
}