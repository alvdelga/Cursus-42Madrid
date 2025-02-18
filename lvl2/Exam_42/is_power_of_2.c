/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:09:09 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/21 12:09:09 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0) 
		n /= 2;
	return ((n == 1) ? 1 : 0);
}

int main()
{
    int i = 32;
    int res = is_power_of_2(i);

    if(res == 1)
        printf("El numero %d es potencia de 2", i);
    else
        printf("El numero %d NO potencia de 2", i);
    return(0);
}