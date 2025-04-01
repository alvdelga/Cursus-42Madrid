/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:50:19 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/10 12:36:46 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

char    **ft_split(char *str)
{
    int i;
    int j;
    int u;
    char **res;

	i = 0;
	u = 0;

    res = (char **)malloc((sizeof (char *) * 255));
    if (!res)
        return (NULL);
	while ((str[i]) && (str[i] == ' '))
	{
		i++;
	}
	j = 0;
    while(str[i])
    {
		
        res[j] = (char *)malloc((sizeof (char) * 4096));
        if (!str[i])
            return(NULL);
        while ((str[i]) && (str[i] != ' '))
        {
            res[j][u++] = str[i++];
        }
		while((str[i]) && (str[i] == ' '))
			i++;
        res[j][u] = '\0';
		u = 0;
		j++;
    }
	res[j] = NULL;

	return (res);

}

// int main(void)
// {
//     char *str = "three words apart";
//     char **words = ft_split(str); // Llamamos a la función

//     // Imprimimos cada palabra obtenida
//     int i = 0;
//     while (words[i])
//     {
//         printf("Palabra: %s\n", words[i]);
//         i++;
//     }

//     return 0;
// }
