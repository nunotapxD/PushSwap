#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack a = {NULL, 0};
    t_stack b = {NULL, 0};

    if (argc == 1)
        return (0);
    
    if (!parse_input(&a, argc, argv))
    {
        write(2, "Error\n", 6);
        free_stack(&a);
        return (1);
    }
    
    if (!is_sorted(&a))
        push_swap(&a, &b);
    
    free_stack(&a);
    free_stack(&b);
    return (0);
}

void    push_swap(t_stack *a, t_stack *b)
{
    if (a->size <= 3)
        sort_small(a);
    else
        sort_big(a, b);
}