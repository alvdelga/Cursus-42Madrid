/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:46:20 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/17 11:32:55 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "stdlib.h"
# include "stdio.h"

char    **ft_split(char *str)
{
    char **res;
    int i = 0;
    int j = 0;
    int k = 0;

    if (!(res = (char **)malloc((sizeof (char *)) * 255)))
        return (NULL);
    
    while (str[i] && str[i] == ' ')
        i++;
    while (str[i])
    {
        res[j] = (char *)malloc((sizeof (char )) * 4056);
        while(str[i] && str[i] != ' ')
        {
            res[j][k++] = str[i++];
        }
        while (str[i] && str[i] == ' ')
            i++;
        res[j][k] = '\0';
        k = 0;
        j++;
    }
    res[j] = NULL;
    return (res);
}

// int main(void)
// {
//     int i = 0;
//     char *str = "hola mundo";
//     char **res = ft_split(str);

//     while(res[i])
//     {
//         printf("%s\n", res[i++]);
//     }
// }