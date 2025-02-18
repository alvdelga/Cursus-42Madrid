/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:33:22 by miguelgo          #+#    #+#             */
/*   Updated: 2025/02/17 20:17:33 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Encuentra el último nodo de la pila
t_stack *find_last(t_stack **stack)
{
    t_stack *move;

    if (!stack || !(*stack)) // Verificación adicional
        return NULL;

    move = *stack;
    while (move->next)
        move = move->next;
    return (move);
}

// Libera la pila
void free_stack(t_stack **stack)
{
    t_stack *tmp;
    t_stack *move;

    if (!stack || !(*stack)) // Verificación de NULL para evitar errores
        return;

    move = *stack;
    while (move != NULL)
    {
        tmp = move;
        move = move->next;
        free(tmp);
    }
}

// Duplica una cadena
char *ft_strdup(const char *s1)
{
    char *copy;
    int i;

    if (!s1) // Verificación de NULL
        return NULL;

    i = 0;
    copy = (char *)malloc(ft_strlen(s1) + 1);
    if (copy == NULL) // Corrección: comparación con NULL
        return NULL;

    while (s1[i] != '\0')
    {
        copy[i] = s1[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}

// Calcula la longitud de una cadena
size_t ft_strlen(const char *s)
{
    int i;

    if (!s) // Verificación de NULL
        return 0;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

// Extrae una subcadena
char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *a;
    unsigned int i;

    if (!s || start > ft_strlen(s)) 
        return (ft_strdup(""));

    if (len > (ft_strlen(s) - start))
        len = (ft_strlen(s) - start);

    a = (char *)malloc(sizeof(char) * (len + 1));
    if (a == NULL) // Corrección: comparación con NULL
        return NULL;

    i = 0;
    while (len--)
    {
        a[i] = s[i + start];
        i++;
    }
    a[i] = '\0';
    return (a);
}

