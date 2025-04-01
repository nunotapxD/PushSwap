#include "push_swap.h"

void    rotate(t_stack *stack)
{
    if (stack->size > 1)
    {
        t_node *first = stack->top;
        t_node *last = stack->top;
        while (last->next)
            last = last->next;
        stack->top = first->next;
        first->next = NULL;
        last->next = first;
    }
}

void    ra(t_stack *a)
{
    if (a->size > 1)
    {
        rotate(a);
        write(1, "ra\n", 3);
    }
}

void    rb(t_stack *b)
{
    if (b->size > 1)
    {
        rotate(b);
        write(1, "rb\n", 3);
    }
}

void    rr(t_stack *a, t_stack *b)
{
    if (a->size > 1 && b->size > 1)
    {
        rotate(a);
        rotate(b);
        write(1, "rr\n", 3);
    }
}

void    reverse_rotate(t_stack *stack)
{
    if (stack->size > 1)
    {
        t_node *last = stack->top;
        t_node *prev = NULL;
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

void    rra(t_stack *a)
{
    if (a->size > 1)
    {
        reverse_rotate(a);
        write(1, "rra\n", 4);
    }
}

void    rrb(t_stack *b)
{
    if (b->size > 1)
    {
        reverse_rotate(b);
        write(1, "rrb\n", 4);
    }
}