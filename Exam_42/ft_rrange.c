/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:02:53 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/17 13:02:53 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_rrange(int start, int end) {
    int size = (start > end) ? start - end + 1 : end - start + 1;
    int *res = (int *)malloc(size * sizeof(int));
    int i = 0;

    if (!res)
        return NULL;

    if (start <= end) {
        while (end >= start) {
            res[i++] = end--;
        }
    } else {
        while (end <= start) {
            res[i++] = end++;
        }
    }

    return res;
}
#include <stdio.h>
int main() {
    int start, end;
    int *result;
    int size, i;

    // Ejemplos de pruebas
    int test_cases[4][2] = {
        {1, 3},
        {-1, 2},
        {0, 0},
        {0, -3}
    };

    for (i = 0; i < 4; i++) {
        start = test_cases[i][0];
        end = test_cases[i][1];
        result = ft_rrange(start, end);
        size = (start > end) ? start - end + 1 : end - start + 1;

        printf("Test %d: start = %d, end = %d\n", i + 1, start, end);
        for (int j = 0; j < size; j++) {
            printf("%d ", result[j]);
        }
        printf("\n");

        free(result);
    }

    return 0;
}