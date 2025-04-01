/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:09:20 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/11 12:49:51 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	fprime(unsigned int nb)
{
    unsigned int prime;

    if(nb == 1)
        printf("1");
    else
    {
        while((nb > 1))
        {
            prime = 2;
            if((nb % prime == 0))
            {
                printf("%d", prime);
                nb /= prime;
                if(nb > 1)
                {
                    printf("*");
                }
                prime--;
            }
            prime++;
        }
    }
}
int		main(int argc, char **argv)
{
	int nb;
	
	if (argc == 2 && *argv[1])
	{
		nb = atoi(argv[1]);
		if (nb > 0)
		{
			fprime((unsigned int) nb);
		}
	}
	printf("\n");
	return (0);
}
