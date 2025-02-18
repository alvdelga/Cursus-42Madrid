/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:18:12 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/18 08:35:29 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Obtiene la lista de números como un array de strings
char **get_list(int argc, char **argv)
{
    char **list;
    int count;

    if (argc == 2)
    {
        list = ft_split(argv[1], ' ');
        if (!list)
            return NULL;
    }
    else
    {
        list = malloc(argc * sizeof(char *));
        if (!list)
            return NULL;
        count = 1;
        while (argv[count] != NULL) // Corrección de '\0' a NULL
        {
            list[count - 1] = argv[count];
            count++;
        }
        list[count - 1] = NULL;
    }
    return list;
}

// Convierte la lista en un array de números
long *start(int argc, char **argv)
{
    long *numbers;
    int c;
    char **list;

    list = get_list(argc, argv);
    if (!list)
        return NULL;

    c = number_list(list);
    if (!c)
        return free_numbers(list, argc);

    numbers = malloc((c + 1) * sizeof(long));
    if (!numbers)
    {
        free_numbers(list, argc);
        return NULL;
    }
    
    numbers[c] = LONG_MAX;
    c = -1;
    while (list[++c] != NULL) // Corrección de '\0' a NULL
        numbers[c] = ft_atoi(list[c]);

    free_numbers(list, argc);
    return numbers;
}

// Llena la pila con los números convertidos
void fill_stack(t_stack **stack, int number)
{
    t_stack *last;
    t_stack *current;

    last = (t_stack *)malloc(sizeof(t_stack));
    if (!last)
        return;
    last->number = number;
    last->next = NULL;

    if (!(*stack))
    {
        *stack = last;
        last->back = NULL;
    }
    else
    {
        current = *stack;
        while (current->next != NULL)
            current = current->next;
        current->next = last;
        last->back = current;
    }
}

// Verifica si la cadena contiene solo dígitos y un posible signo
int check_digit(char *list)
{
    int i = 0;

    if (!list) // Evitar posibles accesos indebidos
        return 0;

    if (list[i] == '-' || list[i] == '+')
    {
        if (list[i + 1] == '\0' || !ft_str_is_numeric(list[i + 1])) // Verificación extra
            return 0;
        i++;
    }

    while (list[i] != '\0')
    {
        if (!(list[i] >= '0' && list[i] <= '9'))
            return 0;
        i++;
    }
    return 1;
}

// Verifica si hay duplicados y si los números están dentro del rango de INT
int check_duplicates(long *numbers)
{
    int i = 0;
    int c;

    if (!numbers) // Evitar accesos indebidos
        return 0;

    while (numbers[i] != LONG_MAX)
    {
        c = i + 1;
        while (numbers[c] != LONG_MAX)
        {
            if (numbers[c] == numbers[i])
                return 0;
            c++;
        }
        i++;
    }

    i = 0;
    while (numbers[i] != LONG_MAX)
    {
        if (numbers[i] < INT_MIN || numbers[i] > INT_MAX)
            return 0;
        i++;
    }
    return 1;
}

