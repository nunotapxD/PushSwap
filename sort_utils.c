/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:29:49 by ntomas-a          #+#    #+#             */
/*   Updated: 2025/05/15 23:29:49 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	move_to_top1(t_move num, t_move neighbour, t_lst **b, t_lst **a)
{
	int	size_a;
	int	size_b;
	int	same_moves;

	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	if (num.b < num.a)
		same_moves = num.b;
	else
		same_moves = num.a;
	if (same_moves > 0 && (neighbour.index > size_a / 2) == (num.index > size_b
			/ 2))
	{
		while (--same_moves > 0)
			rrr_or_rr(a, b, size_b, num);
		num.index = find_idx(b, num.num);
		neighbour.index = find_idx(a, neighbour.num);
	}
	while ((*b)->content != num.num)
		rrb_or_rb(b, num, size_b);
	if (neighbour.to_top == false)
		rra_or_ra(neighbour, size_a, a);
	else
		rra_or_ra(neighbour, size_a, a);
	free(num.neighbour);
}

void	rrr_or_rr(t_lst **a, t_lst **b, int size_b, t_move num)
{
	if (num.index > size_b / 2)
		rrr(a, b);
	else
		rr(a, b);
}

void	rrb_or_rb(t_lst **b, t_move num, int size_b)
{
	if (num.index > size_b / 2)
		rrb(b);
	else
		rb(b);
}

void	rra_or_ra(t_move neighbour, int size_a, t_lst **a)
{
	if (neighbour.to_top == false)
	{
		while (neighbour.node->next)
		{
			if (neighbour.index > size_a / 2)
				rra(a);
			else
				ra(a);
		}
	}
	else
	{
		while ((*a)->content != neighbour.num)
		{
			if (neighbour.index > size_a / 2)
				rra(a);
			else
				ra(a);
		}
	}
}

void	move_to_top2(t_lst **a, t_lst **b)
{
	t_move	num;
	t_move	neighbour;

	num = numb_moves((*a), (*b));
	neighbour = *num.neighbour;
	move_to_top1(num, neighbour, b, a);
}
