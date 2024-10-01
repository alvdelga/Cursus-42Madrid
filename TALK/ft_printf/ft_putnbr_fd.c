/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:09:06 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/05 13:09:12 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd, int i)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		i++;
	}
	if (n > 9)
	{
		i = ft_putnbr_fd(n / 10, 1, i);
	}
	c = n % 10 + '0';
	write(fd, &c, 1);
	i++;
	return (i);
}
