/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:25:50 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/18 15:20:58 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	str_chr(char const *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*new;
	size_t	len;
	size_t	k;

	i = 0;
	k = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	while (str_chr(set, s1[i]) && s1[i])
		i++;
	while (len > 0 && str_chr(set, s1[len - 1]))
		len--;
	if (len < i)
		len = i;
	new = malloc(len - i + 1);
	if (!new)
		return (NULL);
	while (i < len)
		new[k++] = s1[i++];
	new[k] = '\0';
	return (new);
}
/*int	main(void)
{
	char const 	*s2 = " ";
	char const 	*set2 = "  ";
	char 		*result2 = ft_strtrim(s2, set2);

	printf("Frase resultante: %s\n", result2);
	free (result2);
		

	char const 	*s1 = "12Hola12Hola12";
	char const 	*set = "12";
	char 		*result = ft_strtrim(s1, set);

	printf("Frase resultante: %s\n", result);
	free (result);
	return (0);
}*/
