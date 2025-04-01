/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:06:18 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/11 11:06:18 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>

char    *ft_strcpy(char *s1, char *s2)
{
    While (*s2)
    {
        *s1++ = *s2++; 
    }
    return (*s1 -*s2);
}
int main()
{
    char *s1;
    char *s2 = "Hola Mundo";

    printf("%d", ft_strcpy(s1, s2));
}