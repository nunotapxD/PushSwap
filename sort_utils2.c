/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:29:37 by ntomas-a          #+#    #+#             */
/*   Updated: 2025/05/15 23:29:37 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move	neighbour_high(t_lst *a, int num_b)
{
	t_move	max;
	t_move	curr;
	int		i;
	int		size;

	i = 0;
	max.found = false;
	size = ft_lstsize(a);
	while (a)
	{
		curr = (t_move){.index = i, .num = a->content, .moves = i,
			.to_top = true, .found = true, .node = a};
		if (curr.index > size / 2)
			curr.moves = size - i + 1;
		if ((max.num > a->content && a->content > num_b) || (max.found == false
				&& a->content > num_b))
			max = curr;
		a = a->next;
		i++;
	}
	return (max);
}

t_move	neighbour_lower(t_lst *a, int num_b)
{
	t_move	min;
	t_move	curr;
	int		i;
	int		size;

	i = 0;
	min.found = false;
	size = ft_lstsize(a);
	while (a)
	{
		curr = (t_move){.index = i, .num = a->content, .moves = i + 1,
			.to_top = false, .found = true, .node = a};
		if (curr.index > size / 2)
			curr.moves = size - i;
		if ((min.num < a->content && a->content < num_b) || (min.found == false
				&& a->content < num_b))
			min = curr;
		a = a->next;
		i++;
	}
	return (min);
}

t_move	find_best_nei(t_lst *s, int num)
{
	t_move	min;
	t_move	max;

	min = neighbour_lower(s, num);
	max = neighbour_high(s, num);
	if (min.found == false)
		return (max);
	else if (max.found == false)
		return (min);
	else if (min.moves < max.moves)
		return (min);
	else if (min.moves > max.moves)
		return (max);
	return (max);
}

void	smallest_top(t_lst **a, int size_list, int index)
{
	int	i;

	i = index;
	if (index + 1 <= (size_list / 2))
	{
		while (i > 0)
		{
			ra(a);
			i--;
		}
	}
	else if (index + 1 > (size_list / 2))
	{
		while (i < size_list)
		{
			rra(a);
			i++;
		}
	}
}

void	reorganize(t_lst **a, int size_list)
{
	int	smaller;
	int	index;

	smaller = encontrar_menor(a);
	index = find_idx(a, smaller);
	while ((*a)->content != smaller)
	{
		if (index > size_list / 2)
			rra(a);
		else
			ra(a);
	}
}
