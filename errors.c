/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:30:43 by ntomas-a          #+#    #+#             */
/*   Updated: 2025/05/15 23:30:43 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_duplicate(int ac, char **av)
{
	int	i;
	int	a;

	i = 1;
	while (i < ac - 1)
	{
		a = i + 1;
		while (a < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[a]))
				return (-1);
			a++;
		}
		i++;
	}
	return (0);
}

int	ft_is_all_number(int ac, char **av)
{
	int	i;
	int	a;

	i = 1;
	while (i < ac)
	{
		a = 0;
		if (!av[i][a])
			return (-1);
		while (av[i][a])
		{
			if ((av[i][a] == '-' || av[i][a] == '+') && a == 0)
			{
				a++;
			}
			if (av[i][a] >= '0' && av[i][a] <= '9')
				a++;
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

int	higher_smaller_int(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) >= INT_MAX || ft_atoi(av[i]) <= INT_MIN)
			return (-1);
		i++;
	}
	return (0);
}

int	check_errors(int ac, char **av)
{
	if (ft_is_all_number(ac, av) == -1 || ft_duplicate(ac, av) == -1
		|| higher_smaller_int(ac, av) == -1)
	{
		return (-1);
	}
	return (0);
}
