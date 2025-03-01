/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:05:10 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/18 22:29:58 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack **a)
{
	t_stack	*move;

	move = *a;
	if (!(*a))
		return (0);
	while (move->next)
	{
		if (move->number < move->next->number)
			move = move->next;
		else
			return (0);
	}
	return (1);
}

int	stack_len(t_stack *a)
{
	int		len;
	t_stack	*move;

	move = a;
	len = 0;
	while (move)
	{
		move = move->next;
		len++;
	}
	return (len);
}

void	move_to_b(t_stack **a, t_stack **b)
{
	t_stack	*move;

	move = get_cheapest(a);
	if (move->upper == 2 && move->objetive->upper == 2)
		rotate_two(a, b, move, 2);
	if (move->upper == 1 && move->objetive->upper == 1)
		rotate_two(a, b, move, 1);
	update_position(*a);
	update_position(*b);
	move_to_upper(a, move, 'a');
	move_to_upper(b, move->objetive, 'b');
	pb(a, b, 1);
}

void	sort(t_stack **a, t_stack **b)
{
	int		len;

	len = stack_len(*a);
	update_position(*a);
	if (len-- > 3)
		pb(a, b, 1);
	if (len-- > 3)
		pb(a, b, 1);
	while (len-- > 3 && !check_sort(a))
	{
		update_a(*a, *b);
		move_to_b(a, b);
	}
	last_three(a);
	while (*b)
	{
		update_b(*a, *b);
		move_to_a(a, b);
	}
	update_position(*a);
	last_step(a);
}

void	update_a(t_stack *a, t_stack *b)
{
	update_position(a);
	objetives_a(a, b);
	calculate_cost(a, b);
	set_cheapest(a);
}
