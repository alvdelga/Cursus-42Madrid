/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:51:34 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/16 19:50:52 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "unistd.h"

int ft_atoi(char *nbr)
{
    int res;
    int i;

    i = 0;
    res = 0;
    while(nbr[i] >= '0' && nbr[i] <= '9')
    {
        res = res * 10 + nbr[i] - '0';
        i++;
    }
    return (res);
}


void ft_putnbr(int nbr)
{
    char c;

    if(nbr > 9)
        ft_putnbr(nbr / 10);
    c = nbr % 10 + '0';
    write(1, &c, 1);
}

int		is_prime(int n)
{
    int i;

    i = 2;
    if (n < 2) // Manejar números menores a 2
        return (0);

    while(i < n)
    {
        if (n % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int		add_prime_sum(int n)
{
    int sum;
    int i;

    sum = 0;
    i = 2;
    while(i <= n)
    {
        if (is_prime(i) == 1)
            sum = sum + i;
        i++;
    }
    return (sum);
}

int main(int argc, char **argv)
{
    int num;

    if (argc == 2 )
    {
        num = ft_atoi(argv[1]);
        ft_putnbr(add_prime_sum(num));
    }
        
    else 
        ft_putnbr(0);
    
    write(1, "\n", 1);
    return(0);
}