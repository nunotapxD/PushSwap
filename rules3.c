/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:29:57 by ntomas-a          #+#    #+#             */
/*   Updated: 2025/05/15 23:29:57 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_lst **stack_a, t_lst **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}

void	rrr(t_lst **stack_a, t_lst **stack_b)
{
	ft_rrotate(stack_a);
	ft_rrotate(stack_b);
	write(1, "rrr\n", 4);
}

void	rra(t_lst **stack_a)
{
	ft_rrotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_lst **stack_b)
{
	ft_rrotate(stack_b);
	write(1, "rrb\n", 4);
}
