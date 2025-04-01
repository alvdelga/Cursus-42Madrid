/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:01:49 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/07 13:01:49 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    char c;

    i = 1;
    if (argc == 2)
    {   
        while(argv[1][i])
        {
        if (argv[1][i] && argv[1][i] == '_')
        {
            i++;
        }
        if(argv[1][i] >= 'A' && argv[1][i] <= 'A' && argv[1][i])
        {
            c = argv[1][i] + 32;
            write(1, &argv[1][i++], 1);
        }
        
    }
}

if (argv[1][0] >= 'Z' && argv[1][i] <= 'Z' && argv[1][i])
            write(1, &argv[1][0], 1);