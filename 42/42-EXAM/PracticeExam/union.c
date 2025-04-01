/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 09:30:59 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/17 10:13:58 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unistd.h"

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    int seen[255] = {0};

    if (argc == 3)
    {
       while(argv[1][i])
       {
            if (!(seen[argv[1][i]]))
            {
                write(1, &argv[1][i], 1);
                seen[argv[1][i]] = 1;
            }
            i++;
       }
       while(argv[2][j])
       {
            if (seen[argv[2][j]] == 0)
            {
                write(1, &argv[2][j], 1);
                seen[argv[2][j]] = 1;
            }
            j++;
       }
    }
    write(1, "\n", 1);
    return (0);
}
