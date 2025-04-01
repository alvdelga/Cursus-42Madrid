/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 10:43:33 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/23 10:43:33 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int digit_counter(int n)
{
    int count;
    int copy;

    copy = n;
    count = 0;
    if(copy == 0)
        return (1);
    if(copy == -2147483648)
        return (11);
    if(copy < 0)
    {
        copy = -copy;
        count++;
    }
    while(copy > 0)
    {
        copy = copy / 10;
        count++;
    }
    return (count);
}

int exp_counter(int n)
{
    int exp;
    int copy;
    int digit;

    copy = n;
    digit = digit_counter(n);
    if(copy == 0)
        return (1);
    if(copy == -2147483648)
        return (1000000000);
    if(copy < 0)
    {
        copy = -copy;
        digit--;
    }
    exp = 1;
    while(--digit)
    {
        exp = exp * 10;
    }
    return (exp);
}

char    *ft_itoa(int nbr)
{
    long long copy;
    char *res;
    int exp;
    int i;

    i = 0;
    exp = exp_counter(nbr);
    copy =(long long)(nbr);
    res = malloc(digit_counter(nbr) + 1);
    if(!res)
        return (NULL);
    if(nbr < 0)
    {
        res[i++] = '-';
        copy = -copy; 
    }
    while(exp > 0)
    {
        res[i++] = (copy / exp) + 48;
        copy = copy % exp;
        exp = exp / 10;
    }
    res[i] = '\0';
    return (res);
}

int main()
{
  int i = 0;

  char *res = ft_itoa(i);

  printf("%s", res);

  return (0);
}