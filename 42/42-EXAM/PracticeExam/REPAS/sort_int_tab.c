/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:05:33 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/17 20:30:59 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i = 0;
    int swap = 1;

    while(swap == 1)
    {
        i = 1;
        swap = 0;
        while (i < size)
        {
            if (tab[i - 1] > tab[i])
            {
                ft_swap(&tab[i - 1], &tab[i]);
                swap = 1;
            }
            i++;
        }
    }
}




void	print_arr(int *tab, unsigned int size)
{
	unsigned int i = 0;
	while (i < size)
	{
		printf("%d, ", tab[i]);
		++i;
	}
	printf("\n");
}

int		main(void)
{
	int tab[] = { 5, -4, 3, -2, 1, 0 };
	unsigned int size = sizeof(tab) / sizeof(*tab);

	print_arr(tab, size);
	sort_int_tab(tab, size);
	print_arr(tab, size);
}