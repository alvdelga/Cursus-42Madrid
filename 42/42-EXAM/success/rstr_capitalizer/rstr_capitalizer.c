/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:48:20 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/17 16:16:20 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unistd.h"

int is_alfam(char c)
{
    return((c >= 'a' && c <= 'z'));
}

int is_alfaM(char c)
{
    return((c >= 'A' && c <= 'Z'));
}

int main(int argc, char **argv)
{
    int i = 0;
    int j = 1;
    char c;

    if(argc == 1)
        return (write(1, "\n", 1), 0);
    while(j < argc)
    {
        i = 0;
        while(argv[j][i])
        {
            if(argv[j][i] && argv[j][i + 1] != '\0' && argv[j][i + 1] == ' ' && is_alfam(argv[j][i]))
            {
               c = argv[j][i] - 32;
                write(1, &c, 1);
            }
            else if(argv[j][i] && argv[j][i + 1] == '\0' && is_alfam(argv[j][i]))
            {
               c = argv[j][i] - 32;
                write(1, &c, 1);
            }
            else if(argv[j][i] && is_alfaM(argv[j][i]) && argv[j][i + 1] != '\0'  && argv[j][i + 1] != ' ')
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
    return (0);
}