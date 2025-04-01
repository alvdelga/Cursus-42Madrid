/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:50:04 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/11 12:04:37 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
    unsigned int lcm;

    lcm = (a < b)? a : b;
    while( a > 0 && b > 0)
    {
        if((lcm % a == 0) && (lcm % b == 0))
            return(lcm);
        lcm += (a < b)? a : b;
    }
   
}
int main(void)
{
    unsigned int num1 = 12;
    unsigned int num2 = 18;

    printf("LCM de %u y %u es: %u\n", num1, num2, lcm(num1, num2));

    return (0);
}



