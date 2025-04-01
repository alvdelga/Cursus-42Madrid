/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:38:31 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/11 15:38:31 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

void ft_putnbr(num)
{
    if( num > 9)
        ft_putnbr(num / 10);
    while(num)
    {
        num = ((num % 10) + '0');
        write(1, &num, 1);
    }
}

int main(int argc, char **argv)
{
    argv = 0;
    ft_putnbr(argc);
    write(1, "\n", 1);
    return (0);
}