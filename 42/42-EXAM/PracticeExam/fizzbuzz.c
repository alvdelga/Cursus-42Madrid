/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:04:10 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/07 14:04:10 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

int main(int argc, char **argv)
{
    int i;

    i = 1;

    while ( i < 100)
    {
        if(i / 3 == 0 )
            write(1, i, 1);
        else if ( i / 5 == 0 )
            write(1, i, 1);
        else
            write(1, i, 1);
        write(1, "\n", 1);
        i++;
    }

}