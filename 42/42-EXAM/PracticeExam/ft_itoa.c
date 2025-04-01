/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:10:41 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/10 16:25:59 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
#include <stdlib.h>

char *reverse(char *res, int sig)
{
	int i;
	int j;
	char *tmp;

	i = 0;
	j = 0;
	while(res[i])
		i++;
	tmp = malloc(i + 1);
	i--;
	if(sig == 1)
		tmp[j++] = '-';
	while(i >= 0)
	{
		tmp[j++] = res[i--];
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*ft_itoa(int nbr)
{
    int i;
    int sig;
    char *res;

    
    sig = 0;
	i = 0;
    res = malloc(20);
    if(!(res))
        return (NULL);
	if(nbr == 0)
		return("0");
    if (nbr == -2147483648)
    {
        return ("-2147483648");
    }
    if (nbr < 0)
    {
        sig = 1;
        nbr *= -1;
    }
    while(nbr > 0)
    {
        res[i++] = (nbr % 10) + '0';
        nbr = nbr / 10;
    }
    res[i] = '\0';
	res = reverse(res, sig);
	if (!res)
		return (NULL);
    return (res);
}

#include <stdio.h>
#include <stdlib.h> // Para free()

// Declaración de la función
char	*ft_itoa(int nbr);

int main(void)
{
    int test_cases[] = {0, 42, -42, 123456, -987654, 2147483647, -2147483648};
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_cases; i++)
    {
        char *result = ft_itoa(test_cases[i]);
        if (result)
        {
            printf("ft_itoa(%d) = \"%s\"\n", test_cases[i], result);
        }
        else
        {
            printf("Error: ft_itoa(%d) devolvió NULL\n", test_cases[i]);
        }
    }
    return 0;
}
