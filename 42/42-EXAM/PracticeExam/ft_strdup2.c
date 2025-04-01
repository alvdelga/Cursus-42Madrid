/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:19:57 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/11 11:19:57 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strdup(char *src)
{
    int i;
    char *cpy;

    cpy = malloc((sizeof (char)) * 20);
    i = 0;
    while(src[i])
    {
        cpy[i] = src[i];
        i++;
    }
    return (cpy);
}