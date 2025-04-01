/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:19:08 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/17 11:19:08 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void    ft_swap(int *a, int *b)
{
    int copy;
    copy = *a;
    *a = *b;
    *b = copy;
}
int main()
{
    int x = 5;
    int y = 10;

    printf("Antes de intercambiar: x = %d, y = %d\n", x, y);
    ft_swap(&x, &y);
    printf("Después de intercambiar: x = %d, y = %d\n", x, y);

    return 0;
}