/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:09:32 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/05 13:09:41 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n, int i)
{
	char	c;

	if (n > 9)
	{
		i = ft_putunsigned(n / 10, i);
	}
	c = n % 10 + '0';
	write(1, &c, 1);
	i++;
	return (i);
}
