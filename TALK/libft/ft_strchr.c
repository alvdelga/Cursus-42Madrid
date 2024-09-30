/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:41:41 by apaterno          #+#    #+#             */
/*   Updated: 2024/01/24 15:41:48 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	let;

	let = (char)c;
	while (*s)
	{
		if (*s == let)
			return ((char *)s);
		s++;
	}
	if (let == '\0')
		return ((char *)s);
	return (NULL);
}
