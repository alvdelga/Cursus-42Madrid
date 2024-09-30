/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:08:40 by apaterno          #+#    #+#             */
/*   Updated: 2024/01/09 18:08:54 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	let;

	i = ft_strlen(s);
	let = (char)c;
	while (i >= 0)
	{
		if (s[i] == let)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
