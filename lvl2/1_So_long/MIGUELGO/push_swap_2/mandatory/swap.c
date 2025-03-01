/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:56:02 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/18 21:50:18 by miguelgo         ###   ########.fr       */
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
