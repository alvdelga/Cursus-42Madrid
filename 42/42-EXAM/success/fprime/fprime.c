/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:49:51 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/14 14:01:57 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "stdio.h"
# include "stdlib.h"

int main(int argc, char **argv)
{
    int prime;
    int num;

    if (argc == 2)
    {
        num = atoi(argv[1]);
        if (num == 1)
        {
            printf("1");
            return (0);
        }
        prime = 2;
        while (num > 1)
        {
            if (num % prime == 0)
            {
                printf("%d", prime);
                num /= prime;
                if(num > 1)
                    printf("*");
            }
            else
                prime++;
        }
    }
    printf("\n");
    return (0);
}