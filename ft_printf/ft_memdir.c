/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:08:21 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/06 18:56:54 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexa_pointer(char *base, unsigned long long n, int c)
{
	unsigned long long	b;

	b = 16;
	if (n >= b)
	{
		c = hexa_pointer(base, n / b, c);
		write (1, &base[n % b], 1);
		c++;
	}
	else if (n < b)
	{
		write (1, &base[n], 1);
		c++;
	}
	return (c);
}

int	ft_memdir(void *p)
{
	unsigned long long	pointer;
	int					i;

	if (p == 0)
		return (ft_putstr_fd("(nil)", 1));
	i = 0;
	pointer = (unsigned long long)p;
	write(1, "0x", 2);
	i = hexa_pointer("0123456789abcdef", pointer, i);
	i += 2;
	return (i);
}
