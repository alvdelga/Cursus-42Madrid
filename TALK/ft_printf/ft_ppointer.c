/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ppointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:05:43 by apaterno          #+#    #+#             */
/*   Updated: 2024/02/19 13:16:35 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ppointer(void *p, char *simbol)
{
	unsigned long	nb;
	int				len;
	int				i;
	char			str[25];

	nb = (unsigned long)p;
	len = 0;
	i = 0;
	if (nb == 0)
		return (ft_putstr("0x0"));
	if (ft_putstr("0x") == -1)
		return (-1);
	len += 2;
	while (nb > 0)
	{
		str[i++] = simbol[nb % 16];
		nb /= 16;
	}
	while (i > 0)
	{
		if (ft_putchar(str[--i]) == -1)
			return (-1);
		len++;
	}
	return (len);
}
