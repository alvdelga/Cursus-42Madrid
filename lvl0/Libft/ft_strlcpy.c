/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:01:20 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/22 16:30:52 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*int main(void) {
    char src[] = "Hola Mundo";
    char dst[20]; 
    size_t len; 

    len = ft_strlcpy(dst, src, sizeof(dst)); 

    printf("%s\n", src);
    printf("%s\n", dst);
    printf("%zu\n", len);

    return 0;
}*/
