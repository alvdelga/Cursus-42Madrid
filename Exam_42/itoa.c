/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_itoa.c                                             :+:      :+::+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:05:43 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/17 17:05:43 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include "stdlib.h"

int digit_counter(int n)
{
    int copy;
    int res;

    copy = n;
    res = 0;
    if(n == 0)
        return (1);
    if(n == -2147483648)
        return(11);
    if(n < 0)
    {
        copy = -copy;
        res++;
    }
    while(copy > 0)
    {
        copy = copy / 10;
        res++;
    }
    return(res);
}

int exp_counter(int n)
{
    int res;
    int count;

    count = digit_counter(n);
    res = 1;
    if(n == 0)
        return (1);
    if(n == -2147483648)
        return (1000000000);
    if(n < 0)
        count--;
    while(--count)
        res = res * 10;
    return (res);
}

char    *ff_itoa(int nbr)
{
    char *res;
    int i;
    long long copy;
    int exp;

    i = 0;
    copy = (long long)nbr;
    exp = exp_counter(nbr);

    res = malloc(digit_counter(nbr) + 1);
    if(!res)
        return (NULL);
    if (nbr < 0)
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

// int main()
// {
//     int i = 123;
//     char *result = ff_itoa(i);
//     printf("%d", i);
//     return (0);
// }

int main() {
    int test_numbers[] = {0, 1, -1, 123, -123, 2147483647, -2147483648};
    int num_tests = sizeof(test_numbers) / sizeof(test_numbers[0]);

    for (int i = 0; i < num_tests; i++) {
        int number = test_numbers[i];
        char *result = ff_itoa(number);
        printf("Number: %d, String: %s\n", number, result);
        free(result); // Liberar la memoria asignada
    }

    return 0;
}