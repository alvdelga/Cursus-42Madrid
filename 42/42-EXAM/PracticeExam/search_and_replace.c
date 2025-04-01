/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:30:12 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/07 21:30:12 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    char a;
    char b;
    char x;

    i = 0;

    if (argc == 4)
    {
        if (argv[2][1] != '\0' || argv[3][1] != '\0')
        {
            write(1, "\n", 1);
            return (0);   
        }
        a = argv[2][0];
        b = argv[3][0];
        while (argv[1][i])
        {
            if (argv[1][i] == a)
            {
                x = b;
                write(1, &x, 1);
            }
            else
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}