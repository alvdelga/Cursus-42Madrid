/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:30:04 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/13 11:37:56 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unistd.h"

int ft_isalfam(char c)
{
    return((c >= 'a') && (c <= 'z'));
}

int ft_isalfaM(char c)
{
    return((c >= 'A') && (c <= 'Z'));
}

int main(int argc, char **argv)
{
    char c;
    int i;
    int count;

    i = 0;
    if (argc == 2)
    {
        while(argv[1][i])
        {
            if(argv[1][i] && ft_isalfam(argv[1][i]))
            {
                c = argv[1][i];
                count = (argv[1][i] - 96);
                while(count-- > 0)
                {
                    write(1, &c, 1);
                }
            }
            else if(argv[1][i] && ft_isalfaM(argv[1][i]))
            {
                c = argv[1][i];
                count = (argv[1][i] - 64);
                while(count-- > 0)
                {
                    write(1, &c, 1);
                }
            }
            else
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}