#include "push_swap.h"

void	push_chunk(t_stack *a, t_stack *b, int min_pivot, int max_pivot)
{
    int		original_size;
    int		pushed;
    int		rotations;

    original_size = a->size;
    pushed = 0;
    rotations = 0;

    while (pushed < original_size && a->size > 3)
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
    }

    // Restaurar as rotações apenas se necessário
    while (rotations > 0 && a->size > 3)
    {
        rra(a);
        rotations--;
    }
}