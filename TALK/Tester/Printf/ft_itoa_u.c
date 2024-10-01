/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanmetol <sanmetol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:51:28 by sanmetol          #+#    #+#             */
/*   Updated: 2023/10/18 19:54:40 by sanmetol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(unsigned int nbr)
{
	unsigned int	count;

	count = 1;
	while (nbr >= 10)
	{
		count++;
		nbr = nbr / 10;
	}
	return (count);
}

char	*ft_itoa_u(unsigned int n)
{
	int				digits;
	char			*str;

	digits = count_digits(n);
	str = (char *)malloc((digits + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[digits] = '\0';
	while (digits--)
	{
		str[digits] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
