/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:39:43 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/17 11:49:17 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "stdio.h"
# include "stdlib.h"
# include "string.h"

int main(int argc, char **argv)
{
    int num1;
    int num2;
    int temp;

    if (argc == 3)
    {
        num1 = atoi(argv[1]);
        num2 = atoi(argv[2]);

        while(num2 != 0)
        {
            temp = num2;
            num2 = num1 % num2;
            num1 = temp;
        }
        printf("%d", num1);
    }
    printf("\n");
    return (0);
}