/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:11:39 by miguelgo          #+#    #+#             */
/*   Updated: 2024/03/21 13:02:07 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

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
