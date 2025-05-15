/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:29:21 by ntomas-a          #+#    #+#             */
/*   Updated: 2025/05/15 23:29:21 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#define MAX_SORT 100000

int	ft_atoi(const char *str)
{
	long int	i;
	long int	total;
	int			sign;

	total = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = (str[i] != '-') - (str[i] == '-');
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		total *= 10;
		total += str[i++] - 48;
	}
	total *= sign;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (total);
}

void	sort_three(int *stack_a)
{
	if (stack_a[0] > stack_a[1] && stack_a[0] < stack_a[2])
		sa(stack_a, 1);
	if (stack_a[0] > stack_a[1] && stack_a[1] > stack_a[2]
		&& stack_a[2] != MAX_SORT)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	if (stack_a[0] > stack_a[1] && stack_a[0] > stack_a[2])
		ra(stack_a, 1);
	if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2]
		&& stack_a[2] != MAX_SORT)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	if (stack_a[0] < stack_a[1] && stack_a[0] > stack_a[2])
		rra(stack_a, 1);
}

int main(int ac, char **av)
{
	int *arr;
  int *arrb;
	int i;

	i = 0;
	if (ac < 2)
		return (printf("%s", "Erro"));
  arr = malloc(sizeof(int) * (ac -1));
  arrb = malloc(sizeof(int) * (ac -1));
	while (i < ac - 1)
	{
		arr[i] = ft_atoi(av[i + 1]);
		i++;
	}
  i = 0;
  while (i < ac - 1)
	{
		sort_three(arr);
		i++;
	}
}