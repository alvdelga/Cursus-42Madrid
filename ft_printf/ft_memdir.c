/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:53:15 by miguelgo          #+#    #+#             */
/*   Updated: 2024/03/21 19:23:47 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

	i = 0;
	pointer = (unsigned long long)p;
	write(1, "0x", 2);
	i = hexa_pointer("0123456789abcdef", pointer, i);
	i += 2;
	return (i);
}
