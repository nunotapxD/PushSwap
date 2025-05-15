/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:30:49 by ntomas-a          #+#    #+#             */
/*   Updated: 2025/05/15 23:30:49 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	define_sort(t_lst **stack_a, t_lst **stack_b, int ac)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	else if (ac == 3)
		sort_two(stack_a);
	else if (ac == 4)
		sort_three(stack_a);
	else if (ac == 5)
		sort_4(stack_a, stack_b);
	else if (ac == 6)
		sort_five(stack_a, stack_b);
	else if (ac > 6)
		sort_rest(stack_a, stack_b);
}

int	stack_sorted(t_lst **stack)
{
	int		val;
	t_lst	*curr;

	if (!stack || !(*stack)->next)
		return (-1);
	val = (*stack)->content;
	curr = (*stack)->next;
	while (curr)
	{
		if (curr->content < val)
			return (0);
		val = curr->content;
		curr = curr->next;
	}
	return (1);
}

t_lst	*create_stack(int ac, char **av)
{
	int		i;
	t_lst	*node;
	t_lst	*start;

	start = NULL;
	i = 1;
	while (i != ac)
	{
		node = ft_addback(ft_atoi(av[i]));
		if (start == NULL)
			start = node;
		else
			ft_lstadd_back(&start, node);
		i++;
	}
	return (start);
}
