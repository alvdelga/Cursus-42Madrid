/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:28:11 by miguelgo          #+#    #+#             */
/*   Updated: 2024/05/05 20:58:24 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_cases(char *str)
{
	ft_printf("\033[0;31m☠️ ❗ %s ❗☠️\n", str);
	exit(1);
}

void	victory(void)
{
	ft_printf("\033[0;32m🏆 YOU WIN 🏆\n");
	exit(1);
}

char	**get_map(char *mapa)
{
	int		fd;
	char	**map;
	int		i;
	int		lines;

	lines = lines_number(mapa, 'l');
	map = malloc(sizeof(char *) * (lines + 1));
	i = 0;
	fd = open(mapa, O_RDONLY);
	while (1)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	lines_number(char *mapa, char c)
{
	int		lines;
	int		chars;
	char	tmp;
	int		fd;

	fd = open(mapa, O_RDONLY);
	chars = 0;
	lines = 0;
	while (read(fd, &tmp, 1))
	{
		chars++;
		if (tmp == '\n')
		{
			if (c == 'c')
				return (chars);
			lines++;
		}
	}
	lines++;
	close(fd);
	return (lines);
}
