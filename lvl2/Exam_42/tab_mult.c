/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:59:36 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/16 14:59:36 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *arg)
{
    int res;
    int i;

    i = 0;
    res = 0;
    while(arg[i])
    {
        if(arg[i] >= '0' && arg[i] <= '9')
        {
            res = (res * 10) + arg[i] - '0';
        }
        i++;
    }
    return (res);
}

void ft_putnbr(int num)
{
    char res;

    if (num < 10)
    {
        res = num + '0';
        write(1, &res, 1);
    }
    else
    {
        ft_putnbr(num / 10);
        ft_putnbr(num % 10);
    }
}

int main(int argc, char **argv)
{
    int nbr;
    int i;
    int x;

    x = 1;
    i = 0;

    if (argc == 2)
    {
        while ( x <= 9 && argv[1])
        {
            ft_putnbr(x);
            nbr = ft_atoi(argv[1]);
            write(1, " x ", 3);
            ft_putnbr(nbr);
            write(1, " = ", 3);
            ft_putnbr(x * nbr);
            write(1, "\n", 1);
            x++;
        }
    }
    write(1, "\n", 1);
    return (0);
}