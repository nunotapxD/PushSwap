#include "push_swap.h"

void    rrr(t_stack *a, t_stack *b)
{
    if (a->size > 1 && b->size > 1)
    {
        reverse_rotate(a);
        reverse_rotate(b);
        write(1, "rrr\n", 4);
    }
}