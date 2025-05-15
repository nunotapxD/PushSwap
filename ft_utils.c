/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:30:39 by ntomas-a          #+#    #+#             */
/*   Updated: 2025/05/15 23:30:39 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * sign);
}

int	ft_lstsize(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	encontrar_menor(t_lst **a)
{
	int		i;
	t_lst	*current;

	i = (*a)->content;
	current = *a;
	while (current)
	{
		if (current->content < i)
			i = current->content;
		current = current->next;
	}
	return (i);
}

int	encontrar_maior(t_lst **a)
{
	int		i;
	t_lst	*current;

	i = (*a)->content;
	current = *a;
	while (current)
	{
		if (current->content > i)
			i = current->content;
		current = current->next;
	}
	return (i);
}

int	find_idx(t_lst **a, int val)
{
	t_lst	*curr;
	int		index;

	curr = *a;
	index = 0;
	while (curr)
	{
		if (curr->content == val)
			return (index);
		index++;
		curr = curr->next;
	}
	return (-1);
}
