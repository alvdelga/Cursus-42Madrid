/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:51:48 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/13 17:11:28 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "stdlib.h"
# include "stdio.h"

void *rever(char *nbr, int sig)
{
    int i;
    int j;
    char *res;

    i = 0;
    j = 0;
    res = malloc(300);
    while(nbr[i])
        i++;
    i--;
    if(sig == -1)
        res[j++] = '-';
    while(i >= 0)
    {
        res[j++] = nbr[i--];
    }
    res[j] = '\0';
    return (res);
}

char	*ft_itoa(int nbr)
{
    char *res;
    char *num;
    int sig;
    int i;

    i = 0;
    sig = 1;
    res = (char *)malloc((sizeof (char)) * 300);
    if (!res)
        return (NULL);
    if (nbr == 0)
        return ("0");
    if (nbr == -2147483648)
        return ("-2147483648");
    if (nbr < 0)
    {
        sig = -1;
        nbr *= -1;
    }
    while(nbr > 0)
    {
        res[i++] = (nbr % 10) + '0';
        nbr /= 10;
    }
    res[i] = '\0';
    num = rever(res, sig);
    return (num);
}

// int main()
// {
//     int i = 42;
//     char *res = ft_itoa(i);

//     printf("%s\n", res);
// }