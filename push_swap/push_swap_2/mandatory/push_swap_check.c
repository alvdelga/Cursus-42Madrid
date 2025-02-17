/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:29:09 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/22 15:52:37 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_str_is_numeric(char str)
{
	if (str < '0' || str > '9')
	{
		return (0);
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		sign;

	sign = 0;
	i = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (sign == 1)
		result = result * -1;
	return (result);
}

t_stack	*get_cheapest(t_stack **stack)
{
	t_stack	*move;

	move = *stack;
	while (move)
	{
		if (move->cheapest == 1)
			return (move);
		move = move->next;
	}
	return (0);
}
