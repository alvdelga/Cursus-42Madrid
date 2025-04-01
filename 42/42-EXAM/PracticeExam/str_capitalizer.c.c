/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:04:26 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/11 08:48:44 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int j;
    char c;

    i = 0;
    j = 1;
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
    if(argc > 1)
    {
        while(argv[j])
        {
            // while(argv[j][i] == ' ')
            // i++;
            while(argv[j][i])
            {
                if((i == 0) && (argv[j][i] >= 'a' && argv[j][i] <= 'z') && (argv[j][i + 1] == ' '))
                {
                    c = argv[j][i++] - 32;
                    write(1, &c, 1);   
                }
				if((i == 0) && (argv[j][i] >= 'a' && argv[j][i] <= 'z'))
				{
					c = argv[j][i++] - 32;
                    write(1, &c, 1);   
				}
                if((i != 0) && (argv[j][i] != ' ') && (argv[j][i - 1] == ' ') && ((argv[j][i] >= 'a' && argv[j][i] <= 'z') || (argv[j][i] >= 'A' && argv[j][i] <= 'Z')))
                {
                    c = (argv[j][i] >= 'a' && argv[j][i] <= 'z')? argv[j][i] - 32 : argv[j][i];
                    write(1, &c, 1);
                }
                else if (argv[j][i] >= 'A' && argv[j][i] <= 'Z' && (i != 0))
                {
                    c = argv[j][i] + 32;
                    write(1, &c, 1);   
                }
                else
                    write(1, &argv[j][i], 1);  
                i++;
            }
			i = 0;
            j++;
			write(1, "\n", 1);
            
        }
		
    }
    return (0);
}