/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atributes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:05:04 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/22 15:53:38 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_position(t_stack *stack)
{
	int		i;
	int		c;
	t_stack	*move;

	c = stack_len(stack);
	move = stack;
	i = 0;
	while (move)
	{
		if (i > (c / 2))
			move->upper = 1;
		else
			move->upper = 2;
		move->position = i;
		i++;
		move = move->next;
	}
}

t_stack	*max_number(t_stack *b)
{
	t_stack	*max;
	t_stack	*move;
	long	number;

	number = LONG_MIN;
	move = b;
	while (move)
	{
		if (move->number > number)
		{
			max = move;
			number = move->number;
		}
		move = move->next;
	}
	return (max);
}

void	calculate_cost(t_stack *a, t_stack *b)
{
	t_stack	*move;
	long	cost;
	int		len_a;
	int		len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	move = a;
	update_position(a);
	update_position(b);
	while (move)
	{
		if (move->upper == 2)
			cost = move->position;
		else if (move->upper == 1)
			cost = len_a - move->position;
		if (move->objetive->upper == 2)
			cost += move->objetive->position;
		else if (move->objetive->upper == 1)
			cost += len_b - move->objetive->position;
		move->cost = cost;
		move = move->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	t_stack	*cheapest;
	t_stack	*move;
	long	cost;

	move = stack;
	cost = LONG_MAX;
	while (move)
	{
		if (move->cost < cost)
		{
			cheapest = move;
			cost = move->cost;
		}
		move = move->next;
	}
	cheapest->cheapest = 1;
}

void	objetives_a(t_stack	*a, t_stack *b)
{
	t_stack	*closest;
	t_stack	*move_b;
	long	number;

	move_b = b;
	number = LONG_MIN;
	while (a)
	{
		while (move_b)
		{
			if (move_b->number < a->number && move_b->number > number)
			{
				closest = move_b;
				number = move_b->number;
			}
			move_b = move_b->next;
		}
		if (number == LONG_MIN)
			a->objetive = max_number(b);
		else
			a->objetive = closest;
		number = LONG_MIN;
		a = a->next;
		move_b = b;
	}
}
