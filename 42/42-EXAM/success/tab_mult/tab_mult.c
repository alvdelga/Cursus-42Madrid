/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:07:20 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/17 12:23:46 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unistd.h"
# include "stdio.h"

int ft_atoi(char *num)
{
    int res = 0;
    int i = 0;

    while(num[i] && num[i] >= '0' && num[i] <= '9')
    {
        res = res * 10 + (num[i] - '0');
        i++;
    }
    return (res);
}

void ft_putnbr(int n)
{
    if (n > 9)
        ft_putnbr(n / 10);
    n = (n % 10) + '0';
    write(1, &n, 1);
}

int main(int argc, char **argv)
{
    int i = 1;
    int res = 0;

    if (argc == 1)
        return (write(1, "\n", 1), 0);
    while(i <= 9)
    {
        int num = ft_atoi(argv[1]);
        ft_putnbr(i);
        write(1, " x ", 3);
        ft_putnbr(num);
        write(1, " = ", 3);
        res = i * num;
        ft_putnbr(res);
        write(1, "\n", 1);
        i++;
    }


    // printf("%d\n", ft_atoi(argv[1]));
}