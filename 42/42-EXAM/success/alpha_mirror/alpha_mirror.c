/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:03:15 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/16 20:18:23 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unistd.h"

int is_alfam(char c)
{
    return((c >= 'a' && c <= 'z'));
}

int is_alfaM(char c)
{
    return((c >= 'A' && c <= 'Z'));
}

int main(int argc, char **argv)
{
    int i;
    char c;
    int j;

    i = 0;
    if (argc == 2)
    {
        while(argv[1][i])
        {
            if(is_alfam(argv[1][i]))
            { 
                c = 'z' - (argv[1][i] - 97);
                write(1, &c, 1);
            }
            else if(is_alfaM(argv[1][i]))
            {
                c = 'Z' - (argv[1][i] - 'A');
                write(1, &c, 1);
            }
            else
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return(0);
}