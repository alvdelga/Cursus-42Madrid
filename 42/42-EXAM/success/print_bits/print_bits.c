/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:26:23 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/17 08:32:30 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unistd.h"
#   include <stdio.h>

void	print_bits(unsigned char octet)
{
    int i;

    i = 7;
    while(i >= 0)
    {
        ((octet >> i) & 1)? write(1, "1", 1) : write(1, "0", 1);
        i--;
    }
}

// int main(void)
// {
//     unsigned char value = 2;  // Puedes cambiar este valor para probar con otros números
//     print_bits(value);
//     printf("\n");  // Agrega un salto de línea para que la salida sea más legible
//     return 0;
// }