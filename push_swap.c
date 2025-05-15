/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:30:17 by ntomas-a          #+#    #+#             */
/*   Updated: 2025/05/15 23:30:17 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
void push_swap(char **av)
{

}
int main(int ac, char **av)
{
	int *arr;
	int i;

	i = 0;
	if (ac < 2)
		return (printf("%s", "Erro"));
	while (i < ac - 1)
	{
		arr[i] = ft_atoi(av[i + 1]);
		i++;
	}

	i = 0;
	while (i < ac -1)
		printf("%d /n", arr[i++]);
}void push_swap(char **av)
{

}
int main(int ac, char **av)
{
	int *arr;
	int i;

	i = 0;
	if (ac < 2)
		return (printf("%s", "Erro"));
	while (i < ac - 1)
	{
		arr[i] = ft_atoi(av[i + 1]);
		i++;
	}

	i = 0;
	while (i < ac -1)
		printf("%d /n", arr[i++]);
}