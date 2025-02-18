/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:00:13 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/18 17:00:13 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    char c;

    i = 0;
    if(argc == 2)
    {
        while(argv[1][i])
        {
            if(argv[1][i] == 'z')
            {
                write(1, "a", 1);
                i++;
            }
            if(argv[1][i] == 'Z')
            {
                write(1, "A", 1);
                i++;
            }
            if(argv[1][i] >= 'a' && argv[1][i] < 'z')
            {
                c = argv[1][i] + 1;
                write(1, &c, 1);
            }
            else if(argv[1][i] >= 'A' && argv[1][i] < 'Z')
            {
                c = argv[1][i] + 1;
                write(1, &c, 1);
            }
            else
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}