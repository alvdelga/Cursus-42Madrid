/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:52:42 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/17 20:00:43 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "stddef.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
    int i = 0;
    int j = 0;
    size_t len = 0;

    while(s[i])
    {
        j = 0;
        while (reject[j])
        {
            if (s[i] == reject[j])
                return (i);
            j++;
        }
        i++;
    }
    return (i);
}