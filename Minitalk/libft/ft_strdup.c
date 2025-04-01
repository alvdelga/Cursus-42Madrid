/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:32:32 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/25 16:54:00 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	lens1;

	lens1 = ft_strlen(s1);
	s2 = malloc((lens1 + 1));
	if (!s2)
		return (NULL);
	while (*s1)
	{
		*s2++ = *s1++;
	}
	*s2 = '\0';
	return (s2 - lens1);
}
/*int main() {
    const char *original = "\n\n-asfdañ;
    char *duplicado = ft_strdup(original);

    printf("Cadena duplicada: %s\n", duplicado);
	free(duplicado);
    return 0;
}*/
