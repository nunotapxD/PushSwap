/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:29:33 by ntomas-a          #+#    #+#             */
/*   Updated: 2025/05/15 23:29:33 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	sort_two(t_lst **a)
{
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

void	sort_three(t_lst **a)
{
	if (((*a)->content > (*a)->next->content)
		&& ((*a)->next->content > (*a)->next->next->content))
	{
		sa(a);
		rra(a);
	}
	else if (((*a)->content < (*a)->next->next->content)
		&& ((*a)->next->content > (*a)->next->next->content)
		&& ((*a)->content < (*a)->next->content))
	{
		sa(a);
		ra(a);
	}
	else if (((*a)->content > (*a)->next->content)
		&& ((*a)->content > (*a)->next->next->content))
		ra(a);
	else if (((*a)->content < (*a)->next->content)
		&& ((*a)->next->content > (*a)->next->next->content))
		rra(a);
	else if ((*a)->content > (*a)->next->content
		&& (*a)->next->content < (*a)->next->next->content)
		sa(a);
}

void	sort_4(t_lst **a, t_lst **b)
{
	smallest_top(a, ft_lstsize(*a), find_idx(&(*a), encontrar_menor(a)));
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_lst **a, t_lst **b)
{
	smallest_top(a, ft_lstsize(*a), find_idx(&(*a), encontrar_menor(a)));
	pb(a, b);
	smallest_top(a, ft_lstsize(*a), find_idx(&(*a), encontrar_menor(a)));
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
