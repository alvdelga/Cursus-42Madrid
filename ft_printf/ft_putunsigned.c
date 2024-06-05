/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:09:40 by miguelgo          #+#    #+#             */
/*   Updated: 2024/03/21 13:17:24 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

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
