/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:02:48 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/12 09:09:56 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "stdio.h"

int    ft_strcmp(char *s1, char *s2)
{
    while((*s1) && (*s2) && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

// int main()
// {
//     char *a = "Hello Word";
//     char *b = "Hello word";

//     int res;
//     res = ft_strcmp(a, b);
//     printf("%d\n", res);
// }