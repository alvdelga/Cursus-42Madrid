/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:53:21 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/10 22:53:21 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

int main()
{
    int i;

    i = 1;
    while(i >= 100)
    {
        if((i % 3 == 0) && (i % 5 == 0))
            write(1, "fizzbuzz", 8);
        else if(i % 3 == 0)
            write(1, "fizz", 4);
        else if(i % 5 == 0)
            write(1, "buzz", 4);
        else
            write(1, &i, 1);
        write(1, "\n", 1);
        i++;
    }
    return (0);
}