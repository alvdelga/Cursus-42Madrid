/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 23:28:42 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/11 07:29:34 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>

int main(int argc, char **argv)
{
    int i;
    int j;
    int len;

    i = 0;
    j = 0;
    len = 0;
    if(argc == 3)
    {
        while(argv[1][len])
            len++;
		printf("Antes %d\n", len);
        while(argv[1][i])
        {
            while(argv[2][j])
            {
                if((argv[1][i]) && (argv[1][i] == argv[2][j]))
                {  
                    len--;
                    i++;
                }
                j++;
            }
            i++;

        }
		printf("despues %d", len);
		if(len <= 0)
		{
			
			return(write(1, "1\n", 2));
		}
        else
        	return(write(1, "0\n", 2));
    }
    write(1, "\n", 1);
    return (0);
}