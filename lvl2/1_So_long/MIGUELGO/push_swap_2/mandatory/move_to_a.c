/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:14:39 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/22 15:52:57 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_a(t_stack **a, t_stack **b)
{
	move_to_upper(a, (*b)->objetive, 'a');
	pa(a, b, 1);
}

void	objetives_b(t_stack	*a, t_stack *b)
{
	t_stack	*closest;
	t_stack	*move_a;
	long	number;

	move_a = a;
	number = LONG_MAX;
	while (b)
	{
		while (move_a)
		{
			if (move_a->number > b->number && move_a->number < number)
			{
				closest = move_a;
				number = move_a->number;
			}
			move_a = move_a->next;
		}
		if (number == LONG_MAX)
			b->objetive = min_number(a);
		else
			b->objetive = closest;
		number = LONG_MAX;
		b = b->next;
		move_a = a;
	}
}

t_stack	*min_number(t_stack *b)
{
	t_stack	*min;
	t_stack	*move;
	long	number;

	number = LONG_MAX;
	move = b;
	while (move)
	{
		if (move->number < number)
		{
			min = move;
			number = move->number;
		}
		move = move->next;
	}
	return (min);
}

void	last_step(t_stack **a)
{
	t_stack	*min;

	min = min_number(*a);
	if (min->upper == 2)
	{
		while (*a != min)
			ra(a, 1);
	}
	else if (min->upper == 1)
	{
		while (*a != min)
			rra(a, 1);
	}
}

void	update_b(t_stack *a, t_stack *b)
{
	update_position(a);
	update_position(b);
	objetives_b(a, b);
}
