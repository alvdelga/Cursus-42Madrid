/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:12:58 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/10 09:25:01 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_power_of_2(unsigned int n)
{
    while(n > 0)
    {
        while (n % 2 == 0)
        {
            n /= 2;
        }
		if ( n == 1)
        	return (1);
		else 
			return (0);
    }
    
}

// int main(void)
// {
//     // Pruebas con diferentes números
//     unsigned int test_cases[] = {1, 2, 4, 8, 16, 32, 64, 127, 128, 255, 256, 1024, 2048, 4096, 5000};
//     int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

//     for (int i = 0; i < num_cases; i++)
//     {
//         printf("is_power_of_2(%u) = %d\n", test_cases[i], is_power_of_2(test_cases[i]));
//     }

//     return 0;
// }