/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:41:17 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/17 17:55:27 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unistd.h"
# include "stdio.h"

int main(int argc, char **argv)
{
    int i = 0;
    int len = 0;

    
    if (argc == 2)
    {
        while(argv[1][i])
        {
            while(argv[1][i] == ' ')
                i++;
            if(argv[1][i] && argv[1][i] != ' ')
            {
                while(argv[1][i] && argv[1][i] != ' ')
                {
                    write(1, &argv[1][i++], 1);
                }
                while(argv[1][i] == ' ')
                i++;
                if (argv[1][i] != '\0')
                    write(1, " ", 1);
            }
        }
    }
    write(1, "\n", 1);
    return (0);
}