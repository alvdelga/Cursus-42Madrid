/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:34:29 by apaterno          #+#    #+#             */
/*   Updated: 2024/01/24 16:34:38 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	lenlt;

	str = (char *)big;
	lenlt = (size_t)ft_strlen(little);
	i = 0;
	if (*little == '\0')
		return (str);
	while (str[i] && i + lenlt <= len)
	{
		j = 0;
		if (str[i] == little[j])
		{
			while (little[j] && little[j] == str[i + j])
				j++;
			if (little[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
