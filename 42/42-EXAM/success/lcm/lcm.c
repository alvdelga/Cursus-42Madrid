/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:36:57 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/17 09:03:23 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
# include <limits.h>

unsigned int    gcd(unsigned int a, unsigned int b)
{
    unsigned int temp;
    while(b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return (temp);
}

unsigned int    lcm(unsigned int a, unsigned int b)
{

    if( a > INT_MAX  || b > INT_MAX)
        return(0);
    if( a == 0 || b == 0)
        return(0);
    return (unsigned long long) a * b / (gcd(a,b));
}

// int main()
// {
//     unsigned int a, b;

//     // Pedir al usuario dos números
//     printf("Introduce dos números: ");
//     scanf("%u %u", &a, &b);

//     // Calcular y mostrar el resultado
//     printf("MCM(%u, %u) = %u\n", a, b, lcm(a, b));

//     return 0;
// }