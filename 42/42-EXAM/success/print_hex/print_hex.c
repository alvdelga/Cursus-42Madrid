/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:11:55 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/15 20:41:26 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unistd.h"
# include "stdlib.h"
# include "stdio.h"

int ft_atoi(char *num)
{
    int res;
    int i;

    i = 0;
    res = 0;

    while(num[i] >= '0' && num[i] <= '9')
    {
        res = res * 10 + (num[i] + '0');
    }
    return (res);

}

int main(int argc, char **argv)
{
    char *hex;
    int num;
    char res[30];
    char res2[30];
    int i;
    int j;

    i = 0;
    j = 0;
    hex = "0123456789abcdef";

    if(argc == 2)
    {
        num = atoi(argv[1]);
        if (num == 0)
            return ('0');
        while(num > 0)
        {
            res[i++] = hex[num % 16];
            num /= 16;
        }
        while(i--)
        {
            write(1, &res[i], 1);
        }

    }
    write(1, "\n", 1);
    return (0);
}