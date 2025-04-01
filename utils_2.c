#include "push_swap.h"

int get_chunk_size(int size)
{
    if (size <= 100)
        return (size / 5); // ~20 elements per chunk
    return (size / 11); // ~50 elements per chunk for 500
}

void sort_small(t_stack *a)
{
    if (a->size == 2)
    {
        if (a->top->value > a->top->next->value)
            sa(a);
    }
    else if (a->size == 3)
    {
        int top = a->top->value;
        int middle = a->top->next->value;
        int bottom = a->top->next->next->value;

        if (top > middle && middle > bottom)      // 3 2 1
        {
            sa(a);
            rra(a);
        }
        else if (top > middle && top > bottom)    // 3 1 2
            ra(a);
        else if (top > middle)                    // 2 1 3
            sa(a);
        else if (top < middle && middle > bottom && top < bottom) // 1 3 2
        {
            sa(a);
            ra(a);
        }
        else if (top < middle && middle > bottom) // 2 3 1
            rra(a);
        // 1 2 3 is already sorted
    }
}

static int get_min(t_stack *stack)
{
    if (!stack || !stack->top)
        return (0);
        
    t_node *current = stack->top;
    int min = current->value;
    
    while (current)
    {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    return (min);
}

static int get_max(t_stack *stack)
{
    if (!stack || !stack->top)
        return (0);
        
    t_node *current = stack->top;
    int max = current->value;
    
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return (max);
}

static void push_chunk(t_stack *a, t_stack *b, int min_pivot, int max_pivot)
{
    int i;
    int size = a->size;
    int rotated = 0;

    i = 0;
    while (i < size && a->size > 3)
    {
        if (a->top->value >= min_pivot && a->top->value <= max_pivot)
        {
            pb(a, b);
        }
        else
        {
            ra(a);
            rotated++;
        }
        i++;
    }
    
    // Restore the rotated elements if needed
    while (rotated > 0 && a->size > 3)
    {
        rra(a);
        rotated--;
        
        if (a->top->value >= min_pivot && a->top->value <= max_pivot)
        {
            pb(a, b);
        }
    }
}

void sort_big(t_stack *a, t_stack *b)
{
    int min_val = get_min(a);
    int max_val = get_max(a);
    int range = max_val - min_val + 1;
    int num_chunks = (a->size <= 100) ? 5 : 11;
    int chunk_size = range / num_chunks;
    
    // Push elements to stack B in chunks
    int i;
    for (i = 1; i <= num_chunks && a->size > 3; i++)
    {
        int min_pivot = min_val + (i - 1) * chunk_size;
        int max_pivot = (i == num_chunks) ? max_val : min_val + i * chunk_size - 1;
        push_chunk(a, b, min_pivot, max_pivot);
    }

    // Sort the remaining elements in stack A
    sort_small(a);

    // Push elements back to stack A in descending order
    while (b->size > 0)
    {
        int max_b = get_max(b);
        int pos = 0;
        t_node *current = b->top;

        // Find position of max element
        while (current && current->value != max_b)
        {
            pos++;
            current = current->next;
        }

        // Optimize the rotation direction
        if (pos <= b->size / 2)
        {
            while (b->top->value != max_b)
                rb(b);
        }
        else
        {
            while (b->top->value != max_b)
                rrb(b);
        }
        pa(a, b);
    }
}