/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:15:25 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/17 17:27:11 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *str)
{
    int i = 0;
    int res = 0;
    int sig = 1;

    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sig = -1;
        i++;
    }
    // while(str[i] && str[i] == ' ')
    //     i++;
    while(str[i] && str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * sig);
}


// int main()
// {
//     char *tests[] = {
//         "42",
//         "-123",
//         "0",
//         "+456",
//         "   789",
//         "10abc",
//         "abc10",
//         "--42",
//         NULL
//     };

//     for (int i = 0; tests[i] != NULL; i++)
//     {
//         printf("ft_atoi(\"%s\") = %d\n", tests[i], ft_atoi(tests[i]));
//     }
    
//     return 0;
// }
