/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:28:35 by apaterno          #+#    #+#             */
/*   Updated: 2024/01/24 16:28:40 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*src1;
	char	*src2;
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return (0);
	src1 = (char *)s1;
	src2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (src1[i] != src2[i])
			return ((unsigned char)src1[i] - (unsigned char)src2[i]);
		i++;
	}
	return (0);
}
