/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prim_sum2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:39:58 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/17 15:08:15 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unistd.h"
# include "stdio.h"

void ft_putnbr(int nbr)
{
    if (nbr > 9)
        ft_putnbr(nbr / 10);
    nbr = (nbr % 10) + '0';
    write(1, &nbr, 1);

}

int ft_atoi(char *num)
{
    int i = 0;
    int res = 0;
    while(num[i] && num[i] >= '0' && num[i] <= '9')
    {
        res = res * 10 + (num[i++] - '0');
    }
    return (res);
}

int is_prime(int n)
{
    int i = 2;
    while ( i < n)
    {
        if (n % i == 0)
            return(0);
        i++;
    }
    return (1);
}

int add_prim_sum(int n)
{
    int i = 2;
    int sum = 0;

    while(i <= n)
    {
        if(is_prime(i) == 1)
        {
            sum += i;
        }
        i++;
    }
    return (sum);
}

int main(int argc, char **argv)
{
    int num;

    if(argc == 2)
    {
        num = ft_atoi(argv[1]);
        ft_putnbr(add_prim_sum(num));
    }
    // printf("%d\n", num);
    // ft_putnbr(num);
    write(1, "\n", 1);
    return (0);
}