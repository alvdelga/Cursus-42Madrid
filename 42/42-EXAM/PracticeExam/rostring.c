/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:27:55 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/11 13:27:55 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_isblank(char c)
{
	return (c == ' ' || c == '\t');
}

void	rostring(char *s)
{
	int		i = 0;
	int		first_word_length = 0;

	while (s[i])
	{
		// skip beggining whitespaces
		while (ft_isblank(s[i]))
			i++;
		if (s[i] && !ft_isblank(s[i]))
		{
			// if it's the beggining
			if (first_word_length == 0)
				// keep the length of first word for later
				while (s[i] && !ft_isblank(s[i++]))
					first_word_length++;
			else
			{
				// for other words, just write it to stdout (+ one whitespace)
				while (s[i] && !ft_isblank(s[i]) && write(1, &s[i++], 1));
				write(1, " ", 1);
			}
		}
	}

	// write first word
	i = 0;
	while (ft_isblank(s[i]))
		i++;
	while (first_word_length--)
		write(1, &s[i++], 1);
}

int		main(int ac, char **av)
{
	if (ac > 1 && *av[1])
		rostring(av[1]);
	write(1, "\n", 1);
	return (0);
}
