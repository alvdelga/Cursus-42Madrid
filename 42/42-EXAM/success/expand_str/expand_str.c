/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:12:52 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/17 15:22:36 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unistd.h"

int main(int argc, char **argv)
{
    int i = 0;
    int first = 0;

    if (argc != 2 || argv[1][0] == '\0')
        return (write(1, "\n", 1)); 
    while(argv[1][i])
    {
        while(argv[1][i] == ' ')
            i++;
        while(argv[1][i] && argv[1][i] != ' ')
        {
            while(argv[1][i] && argv[1][i] != ' ')
                write(1, &argv[1][i++], 1);
            while(argv[1][i] == ' ')
                i++;
            if(argv[1][i] != '\0')
                write(1, "   ", 3);
        }
        
    }
    write(1, "\n", 1);
    return (0);
}