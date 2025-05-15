/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:30:31 by ntomas-a          #+#    #+#             */
/*   Updated: 2025/05/15 23:30:31 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;

	b = NULL;
	if (ac < 2)
		exit(EXIT_FAILURE);
	if (check_errors(ac, av) == -1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	a = create_stack(ac, av);
	if (stack_sorted(&a))
	{
		free(a);
		free(b);
		exit(EXIT_SUCCESS);
	}
	define_sort(&a, &b, ac);
	free(a);
	free(b);
	return (0);
}
