/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:07:27 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/05 13:08:03 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base);

int	ft_cases(va_list args, char *format, int i)
{
	int	c;

	c = 0;
	if (format[i] == 's')
		c += ft_putstr_fd(va_arg(args, char *), 1);
	else if (format[i] == 'c')
		c += ft_putchar_fd((char)va_arg(args, int), 1);
	else if (format[i] == 'i' || format[i] == 'd')
		c += ft_putnbr_fd((int)va_arg(args, int), 1, 0);
	else if (format[i] == 'u')
		c += ft_putunsigned((unsigned int)va_arg(args, unsigned int), 0);
	else if (format[i] == 'x')
		c += ft_putnbr_base((unsigned int)
				va_arg(args, int), "0123456789abcdef");
	else if (format[i] == 'X')
		c += ft_putnbr_base((unsigned int)
				va_arg(args, int), "0123456789ABCDEF");
	else if (format[i] == '%' && format[i - 1] == '%')
		c += ft_putchar_fd('%', 1);
	else if (format[i] == 'p')
		c += ft_memdir(va_arg(args, void *));
	return (c);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr >= 16)
	{
		i += ft_putnbr_base(nbr / 16, base);
		i += ft_putnbr_base(nbr % 16, base);
	}
	else
	{
		ft_putchar_fd(base[nbr], 1);
		i++;
	}
	return (i);
}

int	ft_is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			lenght;

	i = 0;
	lenght = 0;
	va_start(args, format);
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%' && ft_is_in_set(format[i + 1], "sXdcxpiu%"))
		{
			lenght += ft_cases(args, (char *)format, ++i);
		}
		else
		{
			write(1, &format[i], 1);
			lenght++;
		}
		i++;
	}
	va_end(args);
	return (lenght);
}
/*#include <stdio.h>
int	main()
{
	ft_printf("%%c ");
	printf("%%c");
	return 0;
}*/
