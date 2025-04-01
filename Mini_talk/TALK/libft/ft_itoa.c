/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:56:51 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/16 14:01:27 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
#include "stdlib.h"

int	digit_counter(int n)
{
	int	i;
	int	copy;

	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	copy = n;
	while (copy > 0)
	{
		copy = copy / 10;
		i++;
	}
	return (i);
}

int	exp_counter(int n)
{
	int	exp;
	int	count;

	count = digit_counter(n);
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (1000000000);
	if (n < 0)
		count--;
	exp = 1;
	while (--count)
		exp = exp * 10;
	return (exp);
}

char	*ft_itoa(int n)
{
	char			*src;
	long int		copy;
	int				i;
	int				exp;

	copy = (long int)n;
	exp = exp_counter(n);
	i = 0;
	src = malloc(digit_counter(n) + 1);
	if (!src)
		return (NULL);
	if (copy < 0)
	{
		src[i++] = '-';
		copy = -copy;
	}
	while (exp > 0)
	{
		src[i++] = (copy / exp) + 48;
		copy = copy % exp;
		exp = exp / 10;
	}
	src[i] = '\0';
	return (src);
}
/*int main()
{
  int num;

  num = -2147483648;
  printf("%s", ft_itoa(num));
  return (0);
}*/
