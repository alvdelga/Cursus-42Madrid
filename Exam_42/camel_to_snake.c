/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:04:36 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/23 19:04:36 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int if_is_lo(char c)
{
    char x;

    if(c >= 'A' && c <= 'Z')
    {
        return (1);
    }
   return (0);    
}

int main(int argc, char **argv)
{
    int i;
    char c;

    i = 0;

    if (argc == 2)
    {
        if(argv[1][i] >= 'a' && argv[1][i] <= 'z' || argv[1][i] >= 'A' && argv[1][i] <= 'Z')
        {
            if(if_is_lo(argv[1][0]))
            {
                c = argv[1][0] + 32;    
                write(1, &c, 1);
            }
            else
            {
                write(1, &argv[1][0], 1);
                i++;
            }
            while(argv[1][i])
            {
                if(if_is_lo(argv[1][i]))
                {
                    write(1, "_", 1);
                    c = argv[1][i] + 32;    
                    write(1, &c, 1);
                }
                else
                    write(1, &argv[1][i], 1);
                i++;
            }
        }
    }
    write(1, "\n", 1);
    return (0);
}