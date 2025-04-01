/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:45:41 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/14 12:04:32 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "string.h"

int main(int argc, char **argv)
{
    int a;
    int b;
    char op;
    int num;

    if (argc == 4)
    {
        a = atoi(argv[1]);
        b = atoi(argv[3]);
        op = argv[2][0];

        if (op == '*')
        {
            num = (a * b);
            printf("%d", num);
        }
        if (op == '/')
        {
            num = (a / b);
            printf("%d", num);
        }
        if (op == '+')
        {
            num = (a + b);
            printf("%d", num);
        }
        if (op == '-')
        {
            num = (a - b);
            printf("%d", num);
        }
        if (op == '%')
        {
            num = (a % b);
            printf("%d", num);
        }
    }
    printf("\n");
    return (0);
}