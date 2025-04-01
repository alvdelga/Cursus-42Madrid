/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:18:56 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/17 19:42:46 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    int ascii[256] = {0};

    if(argc == 3)
    {
        while (argv[2][i])
        {
            if (ascii[argv[2][i]] == 0)
                ascii[argv[2][i]] = 1;
            i++;
        }
        i = 0;
        while(argv[1][i])
        {
            if (ascii[argv[1][i]] == 1)
            {
                ascii[argv[1][i]] = 2;
                write(1, &argv[1][i], 1);
            }
            i++; 

        }

    }
    write(1, "\n", 1);
    return (0);
}