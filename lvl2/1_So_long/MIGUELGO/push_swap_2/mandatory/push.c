/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:13:39 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/22 21:25:55 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!(*src))
		return ;
	tmp = *src;
	*src = tmp->next;
	if (*src)
		tmp->next->back = NULL;
	tmp->next = *dest;
	if (*dest)
		(*dest)->back = tmp;
	tmp->back = NULL;
	*dest = tmp;
}

void	pa(t_stack **a, t_stack **b, int c)
{
	push(b, a);
	if (c == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int c)
{
	push(a, b);
	if (c == 1)
		write(1, "pb\n", 3);
}
