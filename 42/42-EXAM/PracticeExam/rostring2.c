/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 06:49:58 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/14 08:15:16 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unistd.h"

int main(int argc, char **argv)
{
    int i;
    int start;
    int end;
    int word;

    i = 0;
    if (argc < 2)
    {
        write(1, "\n", 1);
        return(0);
    }
    if (argc >= 2)
    {
        while(argv[1][i] && argv[1][i] == ' ')
            i++;
        start = i;
        while(argv[1][i] && argv[1][i] != ' ')
            i++;
        end = i - 1;
        if (argv[1][i] != ' ')
            word = 2;
        while(argv[1][i])
        {
            if(argv[1][i] && argv[1][i] != ' ')
            {
                write(1, &argv[1][i++], 1);
            }
            else if(argv[1][i] && argv[1][i] == ' ')
            {
                if ((i != end +1))
                    write(1, " ", 1);
                while(argv[1][i] && argv[1][i] == ' ')
                    i++;
            }
        }
        if ((start == 0) && (i != 0) && (argv[1][end + 1] != ' ') && (start !=0))
            write(1, " ", 1);
        if(argv[1][i] && argv[1][i+1] == '\0')
            write(1, " ", 1);
        if(argv[1][i] == '\0' && argv[1][i] == ' ' ||  argv[1][i - 1] != ' ' && word !=2)
             write(1, " ", 1);
        while(argv[1][start] && argv[1][start] != ' ')
        {
            write(1, &argv[1][start++], 1);
        }
        
    }
    write(1, "\n", 1);
    return (0);
}
