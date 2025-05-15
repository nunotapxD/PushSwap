/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:29:43 by ntomas-a          #+#    #+#             */
/*   Updated: 2025/05/15 23:29:43 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move	numb_moves(t_lst *a, t_lst *b)
{
	t_move	min;
	t_move	curr;
	t_move	best;
	int		i;
	int		size;

	i = 0;
	min.found = false;
	min.neighbour = NULL;
	size = ft_lstsize(b);
	while (b)
	{
		curr = (t_move){.index = i, .num = b->content, .b = i, .to_top = true,
			.found = true, .node = b};
		if (curr.b > size / 2)
			curr.b = size - i + 1;
		best = find_best_nei(a, b->content);
		curr.a = best.moves;
		curr.moves = curr.a + curr.b;
		if (!min.found || min.moves > curr.moves)
			min = comp(min, curr, best);
		b = b->next;
		i++;
	}
	return (min);
}

t_move	comp(t_move min, t_move curr, t_move best)
{
	free(min.neighbour);
	min = curr;
	min.neighbour = malloc(sizeof(t_move));
	*min.neighbour = best;
	return (min);
}
