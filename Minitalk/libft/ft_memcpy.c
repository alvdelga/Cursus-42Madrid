/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:23:06 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/23 21:24:53 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
#include "string.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned const char		*s;
	unsigned char			*d;
	size_t					i;

	s = ((unsigned char *)src);
	d = ((unsigned char *)dst);
	i = 0;
	while (dst == src || !n)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
/*int main()
{
  char copia[] = "Hola mundo";
  char cadena[20];

  ft_memcpy(cadena, copia, strlen(copia) + 1);

  printf("%s", cadena);
  return (0);
}*/
