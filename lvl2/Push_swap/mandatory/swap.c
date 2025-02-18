/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:56:02 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/18 08:31:06 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*move;

	if (!(*stack) || !(*stack)->next)
		return ;
	move = (*stack)->next;
	(*stack)->next = move->next;
	if (move->next)
		move->next->back = *stack;
	move->next = *stack;
	(*stack)->back = move;
	*stack = move;
}

void	sa(t_stack **a, int c)
{
	swap(a);
	if (c == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int c)
{
	swap(b);
	if (c == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int c)
{
	swap(a);
	swap(b);
	if (c == 1)
		write(1, "ss\n", 3);
}
