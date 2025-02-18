/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:18:04 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/18 08:35:12 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rota dos pilas simultáneamente en la misma dirección
void rotate_two(t_stack **a, t_stack **b, t_stack *cheapest, int c)
{
    if (!a || !b || !cheapest || !cheapest->objetive) // Verificación de NULL
        return;

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

// Realiza la operación de reverse rotate en una pila
void reverse_rotate(t_stack **stack)
{
    t_stack *last;

    if (!stack || !(*stack) || !(*stack)->next) // Verificación de NULL
        return;

    last = find_last(stack);
    
    if (!last || !last->back) // Verificación de NULL
        return;

    last->back->next = NULL;
    last->next = *stack;
    last->back = NULL;
    *stack = last;
    last->next->back = last;
}

// Reverse rotate en la pila A con salida condicional
void rra(t_stack **a, int c)
{
    if (!a || !(*a)) // Verificación de NULL
        return;

    reverse_rotate(a);
    if (c == 1)
        write(1, "rra\n", 4);
}

// Reverse rotate en la pila B con salida condicional
void rrb(t_stack **b, int c)
{
    if (!b || !(*b)) // Verificación de NULL
        return;

    reverse_rotate(b);
    if (c == 1)
        write(1, "rrb\n", 4);
}

// Reverse rotate en ambas pilas con salida condicional
void rrr(t_stack **a, t_stack **b, int c)
{
    if (!a || !b || !(*a) || !(*b)) // Verificación de NULL
        return;

    reverse_rotate(a);
    reverse_rotate(b);
    if (c == 1)
        write(1, "rrr\n", 4);
}

