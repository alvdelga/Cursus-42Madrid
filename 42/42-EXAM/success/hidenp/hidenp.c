/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:49:09 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/13 15:20:16 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unistd.h"
# include "stdio.h"
# include "string.h"

int main(int argc, char **argv)
{
    int i;
    int j;
    int count;
    int len;

    i = 0;
    j = 0;
    count = 0;
    if (argc == 3)
    {
        len = strlen(argv[1]);
        while (argv[1][i])
        {
            while (argv[2][j])
            {
                if ((argv[1][i] == argv[2][j]))
                {
                    count++;
                    j++;
                    i++;
                }
                else
                    j++;
            }
            i++;
        }
        // count += 2;
        // printf("\n%d\n", count);
        // printf("\n%d\n", len);
        if (count == len)
            write(1, "1", 1);
        else
            write(1, "0", 1);
    }
    // printf("\n%d\n", count);
    write(1, "\n", 1);
    return (0);
}