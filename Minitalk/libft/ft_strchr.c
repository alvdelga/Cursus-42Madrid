/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:22:27 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/18 14:20:36 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c && str[i] != '\0')
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
/*int main()
{
  char s[] = "Hola que tal";
  char c =  'l';
  char *resultado = ft_strchr(s, c);
  printf("%s", resultado);
}*/
