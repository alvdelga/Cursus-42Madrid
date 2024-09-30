/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:18:32 by apaterno          #+#    #+#             */
/*   Updated: 2024/01/24 17:18:41 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ftstrcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup(const char *s)
{
	char	*p;
	int		size;

	size = ft_strlen(s) + 1;
	p = (char *)malloc(sizeof(char) * size);
	if (p == NULL)
		return (NULL);
	ftstrcpy(p, s);
	return (p);
}
