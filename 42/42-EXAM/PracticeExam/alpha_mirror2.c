/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:38:53 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/08 07:38:53 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

int main(int argc, char **argv)
{
    char m;
    char M;
    char c;
    int i;

    i = 0;
    if(argc == 2)
    {
        while(argv[1][i])
        {
            m = argv[1][i] - 'a';
            M = argv[1][i] - 'A';
            if ((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z'))
            {
                c = (argv[1][i] >= 'a' && argv[1][i] <= 'z') ? ('z' - 'm') : ('Z' - 'M');
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