/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:16:25 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/17 10:26:53 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unistd.h"
# include "stdio.h"

void ft_putnbr(int nbr)
{
    if(nbr > 9)
        ft_putnbr(nbr / 10);
    nbr = (nbr % 10) + '0';
    write(1, &nbr, 1);

}

int main(int argc, char **argv)
{

    if (argc == 1)
        return (write(1, "0\n", 2), 0);
    if (argc > 1)
    {
        ft_putnbr(argc - 1);
        write(1, "\n", 1);
    }
}