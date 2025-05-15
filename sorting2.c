/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:29:26 by ntomas-a          #+#    #+#             */
/*   Updated: 2025/05/15 23:29:26 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_rest(t_lst **a, t_lst **b)
{
	int	size;
	int	aver;

	size = ft_lstsize(*a);
	while ((size - 5) > 0)
	{
		pb(a, b);
		size--;
	}
	sort_five(a, b);
	while (*b)
	{
		move_to_top2(a, b);
		pa(a, b);
	}
	reorganize(a, ft_lstsize(*a));
}
