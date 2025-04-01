/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:29:05 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/13 13:45:37 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "stdio.h"

int		max(int* tab, unsigned int len)
{
    int i;
    int j;
    int res;

    i = 0;
    j = 1;
    res = tab[0];
    while(len--)
    {
        if (tab[i] > tab[j])
        {
            res = tab[i];
            j++;
        }
        else
            i++, j++;
    }
    return (res);
}

// int main()
// {
//     unsigned int num[] = {0, 2, 1};
//     unsigned int res;
    
//     res = max(num, 3);
//     printf("%d\n", res);
//     return (0);
// }
// int main(void)
// {
//     int array1[] = {3, 9997, 2, 9, 5};

//     printf("Max array1: %d\n", max(array1, 5)); // Debe imprimir 9
   

//     return 0;
// }