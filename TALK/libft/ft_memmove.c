/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:46:35 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/23 21:28:33 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char		*p_str1;
	unsigned const char	*p_str2;

	p_str1 = (unsigned char *)str1;
	p_str2 = (unsigned const char *)str2;
	if (str1 < str2)
		return (ft_memcpy(str1, str2, n));
	if (!n || str1 == str2)
		return (str1);
	while (n--)
		p_str1[n] = p_str2[n];
	return (str1);
}
/*int main()
{
	char str[20];
	char copia[] = "Hola Mundo";
 
   printf("%zu\n", strlen(str));
   printf("%zu\n", sizeof(str));
   ft_memmove(str, copia, sizeof(copia));
   printf("%s\n", str);
   printf("%zu\n", strlen(str));
   printf("%zu\n", sizeof(str));
}*/
