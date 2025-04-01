#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

// Operations
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// Utils
t_node	*new_node(int value);
void	free_stack(t_stack *stack);
int		is_sorted(t_stack *a);
int		is_duplicate(t_stack *a, int value);
int		parse_input(t_stack *a, int argc, char **argv);
int		ft_atoi_check(const char *str, int *error);
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
int		get_pos(t_stack *stack, int value);

// Sorting
void	push_swap(t_stack *a, t_stack *b);
void	sort_small(t_stack *a);
void	sort_big(t_stack *a, t_stack *b);
void	push_chunk(t_stack *a, t_stack *b, int min, int max);

#endif