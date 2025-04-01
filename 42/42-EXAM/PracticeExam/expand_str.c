/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:29:39 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/10 11:29:24 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
	i--;
	while(str[i] == ' ')
		i--;
	i++;
    return (i);
}

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 2)
    {
        while(argv[1][i] == ' ')
                i++;
        while(argv[1][i])
        {
            if (((i != ft_strlen(argv[1])) && (argv[1][i] == ' ')) )
            {
				while(argv[1][i] == ' ')
					i++;
				i--;
				if ((i < ft_strlen(argv[1])))
					write(1, "   ", 3);
            }
            else if(argv[1][i] == ' ' && (i != ft_strlen(argv[1])))
            {
                i++;
            }
			else if(argv[1][i] != ' ')
				write(1, &argv[1][i], 1);
            i++;
        }
    }
	write(1, "\n", 1);
	return (0);
}
// -----------

// #include <unistd.h>

// int		main(int argc, char const *argv[])
// {
// 	int		i;
// 	int		flg;

// 	if (argc == 2)
// 	{
// 		i = 0;
// 		while (argv[1][i] == ' ' || argv[1][i] == '\t')
// 			i += 1;
// 		while (argv[1][i])
// 		{
// 			if (argv[1][i] == ' ' || argv[1][i] == '\t')
// 				flg = 1;
// 			if (!(argv[1][i] == ' ' || argv[1][i] == '\t'))
// 			{
// 				if (flg)
// 					write(1, "   ", 3);
// 				flg = 0;
// 				write(1, &argv[1][i], 1);
// 			}
// 			i += 1;
// 		}
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }