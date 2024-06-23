/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:57:32 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/21 09:57:32 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

int digit_count(int n)
{
    int i;

    i = 0;
    if(n == 0)
        return (1);
    if( n == -2147483648)
        return (11);
    if(n < 0)
    {
        n = -n;
        i++;
    }
    while(n > 0)
    {
        n /= 10;
        i++;
    }
    return (i);
}

int exp_counter(int n)
{
    int dig = digit_count(n);
    int res;

    if(n == 0)
        return (1);
    if( n == -2147483648)
        return (1000000000);
    if(n < 0)
        dig--;
    res = 1;
    while(--dig) 
        res = res * 10;
    return (res);
}

char    *ft_itoa(int nbr)
{
    int i;
    long long copy;
    int exp = exp_counter(nbr);
    char *res;

    i = 0;
    copy = (long long)nbr;
    res = malloc(digit_count(nbr) + 1);
    if(!res)
        return (NULL);
    if(copy < 0)
    {
        res[i++] = '-';
        copy = -copy;
    }
    while(exp > 0)
    {
        res[i++] = (copy / exp) + '0';
        copy = copy % exp;
        exp = exp / 10;
    }
    res[i] = '\0';
    return (res);
}

int main()
{
    int i = -2147483648;
    char *res = ft_itoa(i);
    printf("%s\n", res);
    free(res);
    return (0);
}