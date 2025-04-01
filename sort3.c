#include "push_swap.h"

static void	push_back_to_a(t_stack *a, t_stack *b)
{
    int		max_b;
    int		pos;

    while (b->size > 0)
    {
        max_b = get_max(b);
        pos = get_pos(b, max_b);

        // Escolher a direção mais eficiente para trazer o maior elemento para o topo
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

void	sort_big(t_stack *a, t_stack *b)
{
    int		min_val;
    int		max_val;
    int		range;
    int		chunks;
    int		i;

    min_val = get_min(a);
    max_val = get_max(a);
    range = max_val - min_val + 1;
    chunks = (a->size <= 100) ? 5 : 11;

    // Dividir os elementos em chunks e empurrar para a pilha B
    i = 0;
    while (i < chunks && a->size > 3)
    {
        int min_pivot = min_val + (i * range / chunks);
        int max_pivot = min_val + ((i + 1) * range / chunks) - 1;
        push_chunk(a, b, min_pivot, max_pivot);
        i++;
    }

    // Ordenar os elementos restantes na pilha A
    sort_small(a);

    // Retornar os elementos da pilha B para A
    push_back_to_a(a, b);
}