/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:34:50 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/17 11:34:50 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    char c;

    i = 0;
    if (argc == 2)
    {
        while(argv[1][i])
        {
            if(argv[1][i] != '_')
            {
                write(1, &argv[1][i], 1);
            }
            else
            {
                i++;
                if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
                {
                    c = argv[1][i] - 32;
                    write(1, &c, 1);
                }
            
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}