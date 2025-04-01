/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:30:10 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/20 13:16:04 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	result = malloc(count * size);
	if (!result)
	{
		free(result);
		result = (void *) '\0';
		return (NULL);
	}
	else
	{
		ft_bzero(result, (count * size));
		return (result);
	}
}
/*int main()
{
    char *array = ft_calloc(5, sizeof(char));

    int i = 0;

 	 while (i < 5)
 	 {
   		 printf("%u", array[i]);
   		 i++;
	 }
 	   return (0);
}*/
