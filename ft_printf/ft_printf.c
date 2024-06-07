/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malvarde <malvarde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:07:27 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/07 11:47:19 by malvarde         ###   ########.fr       */
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

// #include <stdio.h>
// int	main()
// {
// 	char *stream = 0;
// 	ft_printf("0,0000000%");
// 	   printf("0,0000000%");
// 	return 0;
// }
