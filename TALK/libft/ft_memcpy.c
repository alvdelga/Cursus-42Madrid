/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:34:50 by apaterno          #+#    #+#             */
/*   Updated: 2024/01/22 12:35:51 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dst;
	char		*str;
	size_t		i;

	if (!dest && !src)
		return (0);
	if (dest == src || n == 0)
		return (dest);
	str = (char *)src;
	dst = (char *)dest;
	i = 0;
	while (i < n)
	{
		dst[i] = str[i];
		i++;
	}
	return (dest);
}
