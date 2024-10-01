/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:05:23 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/17 00:05:23 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

void ft_expand(char *str)
{
    int i;

    i = 0;
    if (str[i] && str[i] == ' ')
        i++;
    while(str[i])
    {
        while(str[i] && str[i] != ' ')
            write(1, &str[i++], 1);
        while(str[i] && str[i] == ' ')
            i++;
        if(str[i - 1] && str[i - 1] == ' ' && ft_strlen(str) > i)
            write(1, "   ", 3);
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        ft_expand(argv[1]);
    else
        write(1, "\n", 1);
    return (0);
}