/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 07:28:19 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/09 07:28:19 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
# include <stdlib.h>
# include <stdio.h>

char    *ft_strdup(char *src)
{
    int i;
    char *dup;
    int len;

    i = 0;
    len = 0;
    while(src[i])
    {
        len++;
        i++;
    }
    dup = malloc(len + 1);
    i = 0;
    while(src[i])
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}
int main(void)
{
    char *original = "Hola, mundo!";
    char *copia;

    copia = ft_strdup(original);
    if (copia)
    {
        printf("Original: %s\n", original);
        printf("Copia: %s\n", copia);
        free(copia);  // Liberar memoria después de usar strdup
    }
    else
    {
        printf("Error: No se pudo asignar memoria.\n");
    }

    return (0);
}