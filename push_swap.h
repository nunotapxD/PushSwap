/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:30:11 by ntomas-a          #+#    #+#             */
/*   Updated: 2025/05/15 23:30:11 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_lst
{
	int				content;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

typedef struct s_move
{
	bool			found;
	bool			to_top;

	int				num;
	int				moves;
	int				index;

	int				a;
	int				b;

	t_lst			*node;
	struct s_move	*neighbour;
}					t_move;

/* --- Movement rules functions --- */
void				sb(t_lst **b);
void				sa(t_lst **a);
void				ss(t_lst **stack_a, t_lst **stack_b);

void				ft_rotate(t_lst **stack);
void				rb(t_lst **stack_b);
void				ra(t_lst **stack_a);
void				ft_rrotate(t_lst **stack);
void				rra(t_lst **stack_a);
void				rrb(t_lst **stack_b);
void				rr(t_lst **stack_a, t_lst **stack_b);
void				rrr(t_lst **stack_a, t_lst **stack_b);

void				pb(t_lst **stack_a, t_lst **stack_b);
void				pa(t_lst **stack_a, t_lst **stack_b);

/* --- ERRORS --- */
int					ft_duplicate(int ac, char **av);
int					ft_is_all_number(int ac, char **av);
int					higher_smaller_int(int ac, char **av);
int					check_errors(int ac, char **av);

/* --- FUNCTIONS --- */
long				ft_atoi(char *str);
int					ft_lstsize(t_lst *lst);
t_lst				*ft_addback(long val);
void				ft_lstadd_back(t_lst **lst, t_lst *new);
t_lst				*ft_lstlast(t_lst *lst);

/* --- SORTS --- */
void				sort_two(t_lst **a);
void				sort_three(t_lst **a);
void				sort_five(t_lst **a, t_lst **b);
void				sort_rest(t_lst **a, t_lst **b);
void				sort_4(t_lst **a, t_lst **b);

/* --- SORTS UTILS--- */
int					encontrar_menor(t_lst **a);
int					encontrar_maior(t_lst **a);

t_lst				*create_stack(int ac, char **av);
int					stack_sorted(t_lst **stack);
void				define_sort(t_lst **stack_a, t_lst **stack_b, int ac);

void				reorganize(t_lst **a, int size_list);
t_move				find_best_nei(t_lst *s, int num);
t_move				numb_moves(t_lst *a, t_lst *b);
t_move				comp(t_move min, t_move curr, t_move best);

void				move_to_top2(t_lst **a, t_lst **b);
void				rrr_or_rr(t_lst **a, t_lst **b, int size_b, t_move num);
void				rrb_or_rb(t_lst **b, t_move num, int size_b);
void				rra_or_ra(t_move neighbour, int size_a, t_lst **a);
void				move_to_top1(t_move num, t_move neighbour, t_lst **b,
						t_lst **a);

void				smallest_top(t_lst **a, int size_list, int index);
t_move				neighbour_high(t_lst *a, int num_b);
t_move				neighbour_lower(t_lst *a, int num_b);
int					find_idx(t_lst **a, int val);

int					main(int ac, char **av);

#endif