/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:36:26 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/18 06:59:45 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "stdlib.h"

int     *ft_range(int start, int end)
{
    int len;
    int *res;

    len = (start >= end)? start - end + 1 : end - start + 1;
    res = (int *)malloc((sizeof (int)) * len);
    while(len--)
    {
        res[len] = (start >= end)? end++ : end--;
    }
    return (res);
}

#include <stdio.h>

int *ft_range(int start, int end);

void print_array(int *arr, int size)
{
    if (!arr) // Si ft_range devuelve NULL
    {
        printf("NULL\n");
        return;
    }
    
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
}

int main(void)
{
    int *arr;
    int size;

    // Caso 1: Rango positivo (ascendente)
    size = 6; // de 1 a 6 (incluido)
    arr = ft_range(1, 6);
    printf("Rango (1,6): ");
    print_array(arr, size);

    // Caso 2: Rango negativo (descendente)
    size = 5; // de -3 a -7
    arr = ft_range(-3, -7);
    printf("Rango (-3,-7): ");
    print_array(arr, size);

    // Caso 3: Un solo valor (start == end)
    size = 0; // No debe crear nada
    arr = ft_range(0, 0);
    printf("Rango (5,5): ");
    print_array(arr, size);

    return 0;
}



