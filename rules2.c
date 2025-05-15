/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:30:02 by ntomas-a          #+#    #+#             */
/*   Updated: 2025/05/15 23:30:02 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_lst **stack)
{
	t_lst	*first;
	t_lst	*last;

	first = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ft_rrotate(t_lst **stack)
{
	t_lst	*temp;

	temp = *stack;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = temp;
	while (temp->next != *stack)
		temp = temp->next;
	temp->next = NULL;
}

void	ra(t_lst **stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_lst **stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
}
