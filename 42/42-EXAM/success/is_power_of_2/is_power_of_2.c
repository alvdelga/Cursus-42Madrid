/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:03:35 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/14 10:14:54 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "stdio.h"

int	    is_power_of_2(unsigned int n)
{
    if (n <= 0)
        return (0);

    while ( n % 2 == 0)
            n /= 2;
    if (n == 1)
        return(1);
    else 
        return (0);
}

// int main()
// {
//     unsigned int i = 4;

//     printf("%d\n", is_power_of_2(i));
// }