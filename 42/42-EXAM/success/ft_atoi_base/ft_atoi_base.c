/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:43:23 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/18 07:23:43 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int value_of(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    else if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    else if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    return (0);
}

int is_valid(char c, int base)
{
    char hex1[17] = "0123456789abcdef";
    char hex2[17] = "0123456789ABCDEF";

    while(base--)
    {
        if(hex1[base] == c || hex2[base] == c )
            return (1);
    }
    return(0);
}

int	ft_atoi_base(const char *str, int str_base)
{
    int i;
    int sig;
    int res;

    i = 0;
    sig = 1;
    res = 0;
    while(str[i] == ' ')
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sig = -1;
        i++;
    }
    while (is_valid(str[i], str_base))
        res = res * str_base + value_of(str[i++]);
    return(res * sig);
}


// int main()
// {
//     printf("Base 10: \"123\" = %d\n", ft_atoi_base("123", 10)); // 123
//     printf("Base 10 (negativo): \"-456\" = %d\n", ft_atoi_base("-456", 10)); // -456
//     printf("Base 2: \"1011\" = %d\n", ft_atoi_base("1011", 2)); // 11
//     printf("Base 8: \"77\" = %d\n", ft_atoi_base("77", 8)); // 63
//     printf("Base 16: \"1A3\" = %d\n", ft_atoi_base("1A3", 16)); // 419
//     printf("Base 16 (minúsculas): \"ff\" = %d\n", ft_atoi_base("ff", 16)); // 255
//     printf("Base 16 (mayúsculas): \"FF\" = %d\n", ft_atoi_base("FF", 16)); // 255
//     printf("Base 16 con signo negativo: \"-7B\" = %d\n", ft_atoi_base("-7B", 16)); // -123
//     printf("Base 5: \"432\" = %d\n", ft_atoi_base("432", 5)); // 117
//     printf("Base 10 con espacios: \"   42\" = %d\n", ft_atoi_base("   42", 10)); // 42
//     printf("Base 10 con múltiples signos: \"--42\" = %d\n", ft_atoi_base("--42", 10)); // 0 (inválido)
//     printf("Base inválida (1): \"%s\" = %d\n", "123", ft_atoi_base("123", 1)); // 0 (inválido)
//     printf("Base inválida (17): \"%s\" = %d\n", "123", ft_atoi_base("123", 17)); // 0 (inválido)
//     printf("Carácter inválido en base 2: \"210\" = %d\n", ft_atoi_base("210", 2)); // 0 (inválido)
//     return 0;
// }

