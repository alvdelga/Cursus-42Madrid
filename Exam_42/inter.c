/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:47:51 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/18 17:47:51 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>

// int		ft_verif_char(char *str, char c, int index)
// {
// 	int		i;

// 	i = 0;
// 	while (i < index)
// 	{
// 		if (str[i] == c)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// void	ft_inter(char *s1, char *s2)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	while (s1[i])
// 	{
// 		if (ft_verif_char(s1, s1[i], i) == 1)
// 		{
// 			j = 0;
// 			while (s2[j])
// 			{
// 				if (s2[j] == s1[i])
// 				{
// 					write(1, &s1[i], 1);
// 					break ;
// 				}
// 				j++;
// 			}
// 		}
// 		i++;
// 	}
// }

// int		main(int argc, char **argv)
// {
// 	if (argc == 3)
// 		ft_inter(argv[1], argv[2]);
// 	write(1, "\n", 1);
// 	return (0);
// }


#include <unistd.h>

int ft_repeat(char *s1, char c, int index)
{
    int i;
    
    i = 0;
    while(i < index)
    {
        if(s1[i] == c)
            return(0);
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if(argc == 3)
    {
        while(argv[1][i])
        {
            j = 0;
            while(argv[2][j])
            {
                if(argv[1][i] == argv[2][j])
                {
                    if(ft_repeat(argv[1], argv[1][i], i) == 1)
                    {
                        write(1, &argv[1][i], 1);
                        break;
                    }
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}