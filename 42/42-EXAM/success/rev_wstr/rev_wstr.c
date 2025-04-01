/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:24:38 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/17 12:59:13 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unistd.h"

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    int first = 0;

    if (argc != 2)
        return(write(1, "\n", 1), 0);
    if (argc == 2)
    {
        while(argv[1][i])
            i++;
        i--;
        while (i >= 0)
        {
            while(i >= 0 && argv[1][i] == ' ')
                i--;
            j = i;
            while(i >= 0 && argv[1][i] != ' ')
                i--;
            write(1, &argv[1][i + 1], j - i);
            if (i > 0)
                write(1, " ", 1);
            first = 1;
        }
    }
    write(1, "\n", 1);
    return (0);
}