/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 07:31:29 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/19 16:26:18 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void ft_putchar(char c, int *len)
{
    *len += write(1, &c, 1);
}
void ft_putstr(char *str, int *len)
{
    int i = 0;

    if (!str)
    {
        *len += write (1, "(null)", 6);
        return ;
    }
    while (str[i] != '\0')
    {
        *len += write (1, &str[i], 1);
        i++;
    }
}
void ft_putnbr(int n, int *len)
{
    if (n == -2147483648)
    {
        ft_putchar('-', len);
        ft_putchar('2', len);
        ft_putnbr(147483648 , len);
    }
    else if (n < 0)
    {
        ft_putchar('-', len);
        n = -n;
        ft_putnbr(n, len);
    }
    else if (n > 9)
    {
        ft_putnbr(n / 10, len);
        ft_putnbr(n % 10, len);
    }
    else
        ft_putchar(n + '0', len);
}

void ft_puthex(unsigned int n, char c, int *len)
{
    if (n >= 16)
    {
        ft_puthex(n / 16, c, len);
        ft_puthex (n % 16, c, len);
    }
    if (n < 16)
    {
       ft_putchar("0123456789abcdef"[n], len);
    }
}

void ft_format(char c, int *len, va_list args)
{
    if (c == 's')
        ft_putstr(va_arg(args, char *), len);
    if (c == 'd')
        ft_putnbr(va_arg(args, int), len);
    if (c == 'x')
        ft_puthex(va_arg(args, unsigned int), c, len);
}

int ft_printf(const char *str, ...)
{
    int i = 0;
    int len = 0;
    va_list args;

    va_start (args, str);
    while (str[i])
    {
        if (str[i] == '%' && str[i + 1])
        {
            i++;
            ft_format(str[i], &len, args);
        }
        else
        {
            len += write (1, &str[i], 1);
        }
        i++;
    }
    // va_end(args);
    return (len);

}




int main(void)
{
    int len;
    char *ptr = NULL;
    // Pruebas básicas para cada tipo de formato
    len = ft_printf("String: %s ", ptr);
    printf("%d\n", len);
    len = printf("String: %s ", ptr);
    printf("%d\n", len);

    ft_printf("numero: %x\n", 160);
    printf("numero: %x\n", 160);

    return 0;
}
