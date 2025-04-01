/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:17:31 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/17 17:04:21 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include <stdlib.h>
#include "libft.h"
#include "stdio.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (len == 0 && haystack == NULL)
		return (NULL);
	if (*needle == '\0' || needle == NULL)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*int	main()
{
	char haystack[] = "Una aguja en un pajar";
	char needle[] = "aguja";
	size_t len = strlen(haystack);	

	char *result = ft_strnstr(haystack, needle, len);
	printf("%s", result);
	return (0);
}*/
