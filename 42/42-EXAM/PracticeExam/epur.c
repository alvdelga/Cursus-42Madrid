/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:03:39 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/07 12:23:12 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int main(int argc, char **argv)
{
    int i;
    char *hex;
    int num;
    char res[10];

    i = 0;
    hex = "0123456789abcdef";

    if (argc == 2)
    {
        num = atoi(argv[1]);
        if (num == 0)
            write(1, "0", 1);
        
        while (num > 0)
        {
            res[i++] = hex[num % 16];
            num /= 16;
        }
        while(i-- >= 0)
        {
            write(1, &res[i], 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}