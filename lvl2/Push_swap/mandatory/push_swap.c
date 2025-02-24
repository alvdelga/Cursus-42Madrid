/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:45:16 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/24 11:26:34 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_args(int argc, char **argv)
{
	int	j;

	j = 1;
	while (j < argc)
	{
		if (argv[j][0] == '\0')
		{
			write(2, "Error\n", 6);
			return (1);
		}
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	long	*numbers;
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = 0;
	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (validate_args(argc, argv))
		return (1);
	numbers = initialize(argc, argv);
	if (!numbers)
		return (1);
	while (numbers[i] != LONG_MAX)
		fill_stack(&a, numbers[i++]);
	free(numbers);
	if (!(check_sort(&a)))
		sort(&a, &b);
	free_stack(&a);
	return (0);
}
