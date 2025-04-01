/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:40:04 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/17 10:45:42 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "stdlib.h"

int     *ft_rrange(int start, int end)
{
    unsigned int len;
    int *res;

    len = (start >= end)? start - end + 1 : end - start + 1;
    res = (int *)malloc((sizeof (int)) * len);

    while(len--)
    {
        res[len] = (start >= end)? start-- : start++;
    }
    return (res);
}