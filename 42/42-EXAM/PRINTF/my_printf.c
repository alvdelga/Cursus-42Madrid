/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:35:44 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/20 14:46:41 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void ft_putstr(char *str, int *len)
{
    int i = 0;

    if (!str)
    {
        *len += write(1, "(null)", 6);
        return ;
    }
    while (str[i])
    {
        *len += write(1, &str[i++], 1);
    }
}

void ft_putnbr(int num, int *len)
{
    if (num == -2147483648)
    {
        *len += write(1, "-2147483648", 11);
        return ;
    }
    if (num < 0)
    {
        *len += write(1, "-", 1);
        num = -num;
    }
    if(num > 9)
    {
        ft_putnbr(num / 10, len);
        ft_putnbr(num % 10, len);
    }
    else
    {
        num = num + '0';
        *len += write(1, &num, 1);
    }
}

void ft_puthex(unsigned int num, int *len)
{
    char *hex = "0123456789abcdef";

    if (num >= 16)
    {
        ft_puthex(num / 16, len);
        ft_puthex(num % 16, len);
    }
    if (num < 16)
    {
        *len += write(1, &hex[num], 1);
    }
}

void ft_format(char c, int *len, va_list args)
{
    if (c == 's')
        ft_putstr(va_arg(args, char *), len);
    if (c == 'd')
        ft_putnbr(va_arg(args, int), len);
    if (c == 'x')
        ft_puthex(va_arg(args, unsigned int), len);
    
}

int ft_printf(const char *str, ...)
{
    int i = 0;
    int len = 0;
    va_list(args);

    va_start(args, str);

    while(str[i])
    {
        if (str[i] == '%')
        {
            i++;
            if (str[i] == '%')
                len += write(1, "%", 1);
            ft_format(str[i], &len, args);
        }
        else
        {
            len += write(1, &str[i], 1);
        }
        i++;
    }
    va_end(args);
    return (len);
}

int main ()
{


printf("%d\n", printf("%d", 14324));
printf("%d\n", ft_printf("%d", 14324));
printf("%d\n", printf("%%hola"));
printf("%d\n", ft_printf("%%hola"));
printf("%d\n", printf("%x", 14324));
printf("%d\n", ft_printf("%x", 14324));

return (0);
}