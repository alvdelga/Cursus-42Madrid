/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:58:26 by angavrel          #+#    #+#             */
/*   Updated: 2016/12/08 17:15:42 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 +'0');
}

int		main(int ac, char **av)
{
	av = 0;
	ft_putnbr(ac - 1);
	write(1, "\n", 1);
}

esto haria lo mismo:?
void ft_putnbr(int n)
{
    if (n == -2147483648)
    
    {
        ft_putchar('-');
        ft_putchar('2');
        ft_putnbr(147483648);
    }
    else if (n < 0)
    {
        ft_putchar('-');
        n = -n;
        ft_putnbr(n);
    }
    else if (n > 9)
    {
        ft_putnbr(n / 10);
		ft_putnbr(n % 10);
    }
    else
        ft_putchar(n + '0');
}



void ft_putnbr(int n)
{
    if (n == -2147483648)
    
    {
        ft_putchar('-');
        ft_putchar('2');
        ft_putnbr(147483648);
    }
    else if (n < 0)
    {
        ft_putchar('-');
        n = -n;
        ft_putnbr(n);
    }
    else if (n > 9)
    {
        ft_putnbr(n / 10);
    }
	ft_putchar(n % 10 + '0');
}