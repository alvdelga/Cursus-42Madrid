/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:51:44 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/16 20:02:07 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unistd.h"

void ft_putnbr(int n)
{
    char c;

    if(n > 9)
        ft_putnbr(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

int main()
{
    int i;

    i = 1;

    while(i <= 100)
    {
        if((i % 3 == 0) && (i % 5 == 0))
            write(1, "fizzbuzz", 8);
        else if (i % 3 == 0)
            write(1, "fizz", 4);
        else if( i % 5 == 0)
            write(1, "buzz", 4);
        else
            ft_putnbr(i);
        write(1, "\n", 1);
        i++;
    }
}