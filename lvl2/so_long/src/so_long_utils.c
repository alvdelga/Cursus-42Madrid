/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:37:49 by miguelgo          #+#    #+#             */
/*   Updated: 2024/05/02 12:16:56 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strnstr(char *haystack, char *needle)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		k = 0;
		while (needle[k] == haystack[i + k] && (i + k))
		{
			if (needle[k + 1] == '\0' && haystack[i + k + 1] == '\0')
				return ((char *)haystack + i);
			k++;
		}
		i++;
	}
	return (0);
}
