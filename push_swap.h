#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
} t_node;

typedef struct s_stack
{
    t_node  *top;
    int     size;
} t_stack;

// operations_1.c
void    swap(t_stack *stack);
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);

// operations_2.c
void    rotate(t_stack *stack);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    reverse_rotate(t_stack *stack);
void    rra(t_stack *a);
void    rrb(t_stack *b);

// operations_3.c
void    rrr(t_stack *a, t_stack *b);

// utils_1.c
t_node  *new_node(int value);
void    free_stack(t_stack *stack);
int     is_sorted(t_stack *a);
int     parse_input(t_stack *a, int argc, char **argv);

// utils_2.c
int     get_chunk_size(int size);
void    sort_small(t_stack *a);
void    sort_big(t_stack *a, t_stack *b);

// push_swap.c
void    push_swap(t_stack *a, t_stack *b);

#endif