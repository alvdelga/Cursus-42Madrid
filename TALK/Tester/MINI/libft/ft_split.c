/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:26:09 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/18 21:36:38 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numstring(char const *s1, char c)
{
	int	contp;
	int	flagm;

	contp = 0;
	flagm = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			flagm = 0;
		else if (flagm == 0)
		{
			flagm = 1;
			contp++;
		}
		s1++;
	}
	return (contp);
}

static int	numchar(char const *s2, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char	**freee(char const **dst, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)dst[j]);
	}
	free(dst);
	return (NULL);
}

static char	**to_divide(char const *s, char **dst, char c, int l)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dst[j] = (char *)malloc(sizeof(char) * numchar(s, c, i) + 1);
		if (dst[j] == NULL)
			return (freee((char const **)dst, j));
		while (s[i] != '\0' && s[i] != c)
			dst[j][k++] = s[i++];
		dst[j][k] = '\0';
		j++;
	}
	dst[j] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		l;

	if (s == NULL)
		return (NULL);
	l = numstring(s, c);
	dst = (char **)malloc(sizeof(char *) * (l + 1));
	if (dst == NULL)
		return (NULL);
	return (to_divide(s, dst, c, l));
}
/*int	main(void)
{
	char const	*s = "Hola,,,,,,,,,que,,,,tal";
	char		c = ',';
	char		**split;
	int			i;
	int			numStrings = 0;

	i = 0;
	split = ft_split(s, c);

	// Contar cuántos elementos no nulos hay en frases
	while (split[numStrings] != NULL) {
		numStrings++;
	}

	// Imprimir el número de frases almacenadas
	printf("Número de frases almacenadas: %d\n", numStrings);

	// Imprimir las frases almacenadas
	for (int i = 0; i < numStrings; i++) {
		printf("split[%d]: %s\n", i, split[i]);
	}

	// Liberar la memoria asignada
	for (int i = 0; i < numStrings; i++) {
		free(split[i]);
	}

	free(split);

	return(0);
}*/
