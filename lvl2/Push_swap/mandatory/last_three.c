/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:49:00 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/18 08:31:06 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para ordenar los últimos tres elementos
void last_three(t_stack **a)
{
    t_stack *max;

    max = max_number(*a);
    if ((*a) == max)
        ra(a, 1);
    else if ((*a)->next == max)
        rra(a, 1);
    if ((*a)->number > (*a)->next->number)
        sa(a, 1);
}

// Función para contar la cantidad de elementos en una lista de strings
int number_list(char **list)
{
    int c = 0;

    if (list == NULL) // Verificación adicional de seguridad
        return 0;

    while (list[c] != NULL) // Cambiado de '\0' a NULL
    {
        if (!check_digit(list[c]))
            return 0;
        c++;
    }
    return c;
}

// Inicializa el array de números
long *initialize(int argc, char *argv[])
{
    long *numbers;

    if (argc == 1)
    {
        write(2, "Error\n", 6);
        return NULL;
    }
    numbers = start(argc, argv);
    if (!numbers)
    {
        write(2, "Error\n", 6);
        return NULL;
    }
    if (!check_duplicates(numbers))
    {
        write(2, "Error\n", 6);
        free(numbers);
        return NULL;
    }
    return numbers;
}

// Libera la memoria de un array de strings
long *free_numbers(char **numbers, int argc)
{
    int i = 0;

    if (numbers == NULL) // Verificación adicional
        return NULL;

    if (argc == 2)
    {
        while (numbers[i] != NULL) // Cambiado de '\0' a NULL
        {
            free(numbers[i]);
            i++;
        }
        free(numbers);
    }
    else
    {
        free(numbers);
    }
    return NULL;
}

