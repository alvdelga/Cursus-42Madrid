/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:22:02 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/10 13:56:11 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

int repeat( char *str, char c, int pos)
{
	int i;

	i = 0;
	while(i < pos)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int same(char n, char c)
{
    if (n == c)
        return (1);
    else
        return (0);
}
int main(int argc, char **argv)
{
    int i;
    int j;
	int flag;

    j = 0;
    i = 0;
	
    if (argc == 3)
    {
        while(argv[1][i])
        {
			j = 0;
			flag = 0;
            while(argv[2][j])
            {
                if (same(argv[1][i], argv[2][j]) && flag == 0 && repeat(argv[1], argv[1][i], i))
                {
                    write(1, &argv[1][i], 1);
					flag = 1;
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
