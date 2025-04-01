/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:57:05 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/10 09:03:27 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

void	ft_putnbr(int n)
{
	char c;

	if (n > 9)
        ft_putnbr(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);

}

int main(void)
{
    // Pruebas con diferentes números
    ft_putnbr(42);
    write(1, "\n", 1);  // Salto de línea

    ft_putnbr(-2147483648);
    write(1, "\n", 1);  

    ft_putnbr(0);
    write(1, "\n", 1);  

    ft_putnbr(123456789);
    write(1, "\n", 1);  

    ft_putnbr(-987654321);
    write(1, "\n", 1);  

    return (0);
}