/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:11:34 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/23 09:20:33 by alvdelga         ###   ########.fr       */
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
	long		res;
	int			negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
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
