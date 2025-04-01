/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:57:50 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/11 16:20:57 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <stdio.h>

char *reverse(char *num, int sig)
{
    int i;
    int j;
    char *res;
    
    j = 0;
    i = 0;
    res = malloc(30);
    if(!res)
        return (0);
    if (sig == 1)
        res[i++] = '-';
    while (num[j])
        j++;
    j--;
    while(j >= 0)
        res[i++] = num[j--];
    return(res);
}

char	*ft_itoa(int nbr)
{
    char *num;
    int sig;
    int i;

    i = 0;
    sig = 0;
    if (!nbr)
        return (0);
    num = (char *)malloc(sizeof (char) * 50);
    if (!num)
        return (0);
    if (nbr == 0)
        return ("0");
    if (nbr == -2147483648)
        return ("-2147483648");
    if(nbr < 0)
    {
        nbr *= -1;
        sig = 1;
    }
    while (nbr > 0)
    {
        num[i++] = (nbr % 10) + '0';
        nbr /= 10;
    }
    num[i] = '\0';
	num = reverse(num, sig);
    return(num);
}

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