/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:18:04 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/24 11:14:35 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rota dos pilas simultáneamente en la misma dirección
void	rotate_two(t_stack **a, t_stack **b, t_stack *cheapest, int c)
{
	if (!a || !b || !cheapest || !cheapest->objetive)
		return ;
	if (c == 2)
	{
		while ((*a != cheapest) && (*b != cheapest->objetive))
			rr(a, b, 1);
	}
	else if (c == 1)
	{
		while ((*a != cheapest) && (*b != cheapest->objetive))
			rrr(a, b, 1);
	}
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = find_last(stack);
	if (!last || !last->back)
		return ;
	last->back->next = NULL;
	last->next = *stack;
	last->back = NULL;
	*stack = last;
	last->next->back = last;
}

void	rra(t_stack **a, int c)
{
	if (!a || !(*a))
		return ;
	reverse_rotate(a);
	if (c == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int c)
{
	if (!b || !(*b))
		return ;
	reverse_rotate(b);
	if (c == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int c)
{
	if (!a || !b || !(*a) || !(*b))
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
	if (c == 1)
		write(1, "rrr\n", 4);
}
