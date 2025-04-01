/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 07:49:51 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/10 08:45:08 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int j;
    char c;

    i = 0;
    j = 1;
    if (argc == 1)
    {
        write(1, "\n", 1);
        return (0);
    }
    if (argc > 1)
    {
        while(j < argc)
        {
            i = 0;
            while(argv[j][i])
            {
                if ((argv[j][0] >= 'a' && argv[j][0] <= 'z') && (i == 0))
                {
                    c = argv[j][i++] - 32;
                    write(1, &c, 1);
                }
                if((argv[j][i] >= 'a' && argv[j][i] <= 'z') && !( i == 0 ) && argv[j][i - 1] == ' ')
                {
                    c = argv[j][i] - 32;
                    write(1, &c, 1);
                }
                else if((argv[j][i] >= 'A' && argv[j][i] <= 'Z')  && (argv[j][i - 1] != ' ') && (i != 0))
                {
                    c = argv[j][i] + 32;
                    write(1, &c, 1);
                }   
                else
                    write(1, &argv[j][i], 1);
                i++;
            }
            write(1, "\n", 1);
            j++;
        }
    }
    return (0);
}