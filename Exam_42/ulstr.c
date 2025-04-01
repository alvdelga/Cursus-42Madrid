/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:35:54 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/21 16:35:54 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char upper(char c)
{
    if(c >= 'a' && c <= 'z')
        c = c - 32;
    else if(c >= 'A' && c <= 'Z')
        c = c + 32;
    return (c);
}

int main(int argc, char **argv)
{
    int i;
    char c;

    i = 0;
    if(argc == 2)
    {
        while(argv[1][i])
        {
            c = upper(argv[1][i]);
            write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}