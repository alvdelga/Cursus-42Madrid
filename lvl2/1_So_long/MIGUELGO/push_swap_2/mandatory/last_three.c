/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:49:00 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/23 15:52:25 by miguelgo         ###   ########.fr       */
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

int	number_list(char **list)
{
	int	c;

	c = 0;
	while (list[c] != '\0')
	{
		if (!check_digit(list[c]))
			return (0);
		c++;
	}
	return (c);
}

long	*initialize(int argc, char *argv[])
{
	long	*numbers;

	if (argc == 1)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
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
	if (argc == 2)
	{
		while (numbers[i])
		{
			free(numbers[i]);
			i++;
		}
		free(numbers);
	}
	else
		free(numbers);
	return (0);
}
