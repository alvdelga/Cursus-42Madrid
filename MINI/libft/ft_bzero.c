/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:32:11 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/22 16:23:10 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = 0;
		i++;
	}
}
/*int main()
{
    char array[5];

    int i = 0;
	
	ft_bzero(array, sizeof(array));

	printf("%s", array);

	 while (i < sizeof(array))
 	 {
   		 printf("%s", array[i]);
   		 i++;
 	 }
  return (0);
}*/
