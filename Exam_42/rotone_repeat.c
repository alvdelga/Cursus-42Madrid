/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:05:58 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/17 17:05:58 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int cont;

    i = 0;
    cont = 0;
    if (argc == 2)
    {
        while(argv[1][i])
        {
            if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
            {
                cont = argv[1][i] - 96;
                while(cont--)
                    write(1, &argv[1][i], 1);
            }
            else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
            {
                cont = argv[1][i] - 64;
                while(cont--)
                    write(1, &argv[1][i], 1);
            }
            else
                write(1, &argv[1][i], 1);
            i++;
        }
    }
}