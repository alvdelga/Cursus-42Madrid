/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:49:00 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/24 11:20:17 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_three(t_stack **a)
{
	t_stack	*max;

	max = max_number(*a);
	if ((*a) == max)
		ra(a, 1);
	else if ((*a)->next == max)
		rra(a, 1);
	if ((*a)->number > (*a)->next->number)
		sa(a, 1);
}

// Función para contar la cantidad de elementos en una lista de strings
int	number_list(char **list)
{
	int	c;

	c = 0;
	if (list == NULL)
		return (0);
	while (list[c] != NULL)
	{
		if (!check_digit(list[c]))
			return (0);
		c++;
	}
	return (c);
}

// Inicializa el array de números
long	*initialize(int argc, char **argv)
{
	long	*numbers;

	numbers = start(argc, argv);
	if (!numbers)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	if (!check_duplicates(numbers))
	{
		write(2, "Error\n", 6);
		free(numbers);
		return (NULL);
	}
	return (numbers);
}

long	*free_numbers(char **numbers, int argc)
{
	int	i;

	i = 0;
	if (numbers == NULL)
		return (NULL);
	if (argc == 2)
	{
		while (numbers[i] != NULL)
		{
			free(numbers[i]);
			i++;
		}
		free(numbers);
	}
	else
	{
		free(numbers);
	}
	return (NULL);
}
