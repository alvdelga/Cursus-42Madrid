/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:39:08 by apaterno          #+#    #+#             */
/*   Updated: 2024/01/24 17:39:13 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ftstrcon(char const *s1, char const *s2, char *dst)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = (char *)malloc(sizeof(char) * size);
	if (p == NULL)
		return (NULL);
	ftstrcon(s1, s2, p);
	return (p);
}
