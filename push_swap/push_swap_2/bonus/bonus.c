/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:28:24 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/23 16:20:18 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../gnl/get_next_line.h"
#include "../mandatory/push_swap.h"

int	main(int argc, char *argv[])
{
	long	*numbers;
	int		i;
	t_stack	*a_bonus;
	t_stack	*b_bonus;

	i = 0;
	a_bonus = NULL;
	b_bonus = NULL;
	if (argc == 1 || argv[1][0] == '\0')
		return (0);
	numbers = initialize(argc, argv);
	if (!numbers)
		return (0);
	while (numbers[i] != LONG_MAX)
	{
		fill_stack(&a_bonus, numbers[i]);
		i++;
	}
	free(numbers);
	read_lines(&a_bonus, &b_bonus);
	last_check(&a_bonus);
	free_stack(&a_bonus);
	return (0);
}
