#include "push_swap.h"

void    swap(t_stack *stack)
{
    if (stack->size >= 2)
    {
        t_node *first = stack->top;
        t_node *second = first->next;
        first->next = second->next;
        second->next = first;
        stack->top = second;
    }
}

void    sa(t_stack *a)
{
    if (a->size >= 2)
    {
        swap(a);
        write(1, "sa\n", 3);
    }
}

void    sb(t_stack *b)
{
    if (b->size >= 2)
    {
        swap(b);
        write(1, "sb\n", 3);
    }
}

void    ss(t_stack *a, t_stack *b)
{
    if (a->size >= 2 && b->size >= 2)
    {
        swap(a);
        swap(b);
        write(1, "ss\n", 3);
    }
}

void    pa(t_stack *a, t_stack *b)
{
    if (b->size > 0)
    {
        t_node *tmp = b->top;
        b->top = tmp->next;
        tmp->next = a->top;
        a->top = tmp;
        a->size++;
        b->size--;
        write(1, "pa\n", 3);
    }
}

void    pb(t_stack *a, t_stack *b)
{
    if (a->size > 0)
    {
        t_node *tmp = a->top;
        a->top = tmp->next;
        tmp->next = b->top;
        b->top = tmp;
        a->size--;
        b->size++;
        write(1, "pb\n", 3);
    }
}