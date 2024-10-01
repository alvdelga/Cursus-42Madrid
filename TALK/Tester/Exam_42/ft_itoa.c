/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:15:09 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/17 10:15:09 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"

int digit_counter(int nbr)
{
    int count;
    int copy;

    count = 0;
    if(nbr == 0)
        return (1);
    if(nbr == -2147483648)
        return (11);
    if(nbr < 0)
    {
        nbr = -nbr;
        count++;
    }
    copy = nbr;
    while(copy > 0)
    {
        copy = copy / 10;
        count++;
    }
    return (count);
}

int exp_counter(int nbr)
{
    int exp;
    int count;

    count = digit_counter(nbr);
    if(nbr == 0)
        return (1);
    if(nbr == -2147483648)
        return (1000000000);
    if(nbr < 0)
        count--;
    exp = 1;
    while (--count)
        exp = exp * 10;
    return(exp);
}

char    *ft_itoa(int nbr)
{
	char			*src;
	long int		copy;
	int				i;
	int				exp;

	copy = (long int)nbr;
	exp = exp_counter(nbr);
	i = 0;
	src = malloc(digit_counter(nbr) + 1);
	if (!src)
		return (NULL);
	if (copy < 0)
	{
		src[i++] = '-';
		copy = -copy;
	}
	while (exp > 0)
	{
		src[i++] = (copy / exp) + 48;
		copy = copy % exp;
		exp = exp / 10;
	}
	src[i] = '\0';
	return (src);
}

int main()
{
    int i = -2147483648;
    char *res = ft_itoa(i);
    printf("%s\n", res);
    free(res);
    return (0);
}

// int main()
// {
//     int nbr = 10;
//     char *result = ft_itoa(nbr);
//     printf("%s", result);
//     return(0);
// }

// int main() {
//     int test_numbers[] = {0, 1, -1, 123, -123, 2147483647, -2147483648};
//     int num_tests = sizeof(test_numbers) / sizeof(test_numbers[0]);

//     for (int i = 0; i < num_tests; i++) {
//         int number = test_numbers[i];
//         char *result = ft_itoa(number);
//         printf("Number: %d, String: %s\n", number, result);
//         free(result); // Liberar la memoria asignada
//     }

//     return 0;
// }