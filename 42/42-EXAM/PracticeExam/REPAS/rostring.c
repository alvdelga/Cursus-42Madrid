/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:30:22 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/16 23:55:45 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unistd.h"

int main(int argc, char **argv)
{
    int i;
    int first_word_len;

    i = 0;
    first_word_len = 0;
    if(argc == 1)
        return(write(1, "\n", 1), 0);
    while(argv[1][i])
    {
        while(argv[1][i] == ' ')
            i++;
        if(argv[1][i] && argv[1][i] != ' ')
        {
            if(first_word_len == 0)
            {
                while(argv[1][i] && argv[1][i++] != ' ')
                {
                    first_word_len++;
                }
            }
            else
            {
                while(argv[1][i] && argv[1][i] != ' ')
                {
                    write(1, &argv[1][i++], 1);
                }
                write(1, " ", 1);
            }
        }
    }
    i = 0;
    while(argv[1][i] == ' ')
        i++;
    while(first_word_len--)
    {
        write(1, &argv[1][i++], 1);
    }
    write(1, "\n", 1);
    return (0);
}