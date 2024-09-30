/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:03:13 by apaterno          #+#    #+#             */
/*   Updated: 2024/02/15 13:26:16 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_itoa_hex(unsigned int nb, char *simbol)
{
	int		len;
	int		i;
	char	str[25];

	len = 0;
	i = 0;
	if (nb == 0)
		return (ft_putchar('0'));
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
