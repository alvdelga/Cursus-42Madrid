/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 22:35:27 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/08 22:41:41 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc ==2)
    {
        while (argv[1][i])
        {
            if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
            {
                if (i > 0)
                {
					write(1, "_", 1);
                    write(1, (char[]){(char) argv[1][i] + 32}, 1);
                }
            }
            else
                write(1, &argv[1][i], 1);
			i++;
        }
    }
    write(1, "\n", 1);
    return (0);
