/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:36:30 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/15 20:08:42 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unistd.h"

int main(int argc, char **argv)
{
    int i;
    int j;
    int u;
    int p;
    int rep;
    int rep2;

    i = 0;
    j = 0;
    u = 0;
    p = 0;
    rep = 0;
    if (argc == 3)
    {
        while(argv[1][i])
        {
            j = 0;
            rep = 0;
            while(argv[2][j])
            {
                rep2 = 0;
                if(argv[1][i] == argv[2][j] && rep == 0)
                {
                    u = i;
                    while(argv[1][u--])
                    {
                        if(argv[1][u] == argv[2][j])
                            rep2 = 1; 
                    }
                    if (rep2 == 0)
                    {
                        write(1, &argv[1][i], 1);
                        rep = 1;
                    }
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}