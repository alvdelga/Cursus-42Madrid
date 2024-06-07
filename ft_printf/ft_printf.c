/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:07:27 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/07 13:55:36 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, char *structure, int i)
{
	int	c;

	c = 0;
	if (structure[i] == 's')
		c += ft_putstr_fd(va_arg(args, char *), 1);
	else if (structure[i] == 'c')
		c += ft_putchar_fd((char)va_arg(args, int), 1);
	else if (structure[i] == 'i' || structure[i] == 'd')
		c += ft_putnbr_fd((int)va_arg(args, int), 1, 0);
	else if (structure[i] == 'u')
		c += ft_putunsigned((unsigned int)va_arg(args, unsigned int), 0);
	else if (structure[i] == 'x')
		c += ft_putnbr_base((unsigned int)
				va_arg(args, int), "0123456789abcdef");
	else if (structure[i] == 'X')
		c += ft_putnbr_base((unsigned int)
				va_arg(args, int), "0123456789ABCDEF");
	else if (structure[i] == '%' && structure[i - 1] == '%')
		c += ft_putchar_fd('%', 1);
	else if (structure[i] == 'p')
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

int	ft_inSet(char c, char const *set)
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
#include <string.h>

int end_percent(const char *str)
{
    size_t len = strlen(str);
    return (str[len - 1] == '%' && str[len - 2] != '%');
}

int	ft_printf(const char *structure, ...)
{
	va_list		args;
	int			i;
	int			lenght;

	i = 0;
	lenght = 0;
	va_start(args, structure);
	if (!structure)
		return (0);
	while (structure[i])
	{
		if (end_percent(structure))
			return(-1);
		if (structure[i] == '%' && ft_inSet(structure[i + 1], "scidXxpu%"))
		{
			lenght += ft_format(args, (char *)structure, ++i);
		}
		else
		{
			write(1, &structure[i], 1);
			lenght++;
		}
		i++;
	}
	va_end(args);
	return (lenght);
}
