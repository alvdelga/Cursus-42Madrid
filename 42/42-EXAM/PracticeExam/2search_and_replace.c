/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2search_and_replace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 07:16:49 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/09 07:16:49 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    char a;
    char b;
    char c;

    i = 0;
    if (argc == 4)
    {
        a = argv[2][0];
        b = argv[3][0];
        if (argv[2][1] != '\0' || argv[3][1] != '\0' )
        {
            write(1, "\n", 1);
            return (0);
        }
        while (argv[1][i])
        {
            if (argv[1][i] == a)
                c = b;
            else
                c = argv[1][i];
            write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}