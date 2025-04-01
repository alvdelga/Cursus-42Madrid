/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:49:38 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/07 22:05:29 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    char c;

    i = 0;
    if (argc == 2)
    {
        char c;
        while (argv[1][i])
        {
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
            {
                c = 'z' - (argv[1][i] - 'a');
                write(1, &c, 1);
            }
            else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
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
    return (0);
}