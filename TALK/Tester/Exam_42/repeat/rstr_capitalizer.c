/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:32:38 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/21 08:32:38 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int space(char c)
{
    return(c == ' ' || c == '\t' || c == '\0');
}

int main(int argc, char **argv)
{
    int i;
    int x;

    x = 0;
    if (argc == 1)
    {
        write(1, "\n", 1);
    }
        while(++x < argc)
        {
            i = 0;
            while(argv[x][i])
            {
                if(argv[x][i] >= 'A' && argv[x][i] <= 'Z' && !space(argv[x][i + 1]))
                {
                    argv[x][i] = argv[x][i] + 32;
                }
                else if(argv[x][i] >= 'a' && argv[x][i] <= 'z' && space(argv[x][i + 1]))
                {
                    argv[x][i] = argv[x][i] - 32;
                }
                write(1, &argv[x][i], 1);
                i++;
            }
            write(1, "\n", 1);
        }
    
    return (0);
}