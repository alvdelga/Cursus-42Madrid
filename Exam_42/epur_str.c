/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:20:23 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/21 12:20:23 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int tab(char c)
{
    if(c == ' ' || c == '\t')
        return (1);
    else
        return (0);
}

int len(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    while(str[i] == ' ')
        i--;
    i--;
    return (i);
}

int main(int argc, char **argv)
{
    int i;
    int leng;

    i = 0;
    if(argc == 2)
    {
        leng = len(argv[1]);
        while(argv[1][i])
        {
            while(tab(argv[1][i]))
                i++;
            while(argv[1][i] && !tab(argv[1][i]))
            {
                write(1, &argv[1][i++], 1);
            }
            if(i < leng)
                write(1, " ", 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}