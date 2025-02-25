/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:39:56 by miguelgo          #+#    #+#             */
/*   Updated: 2024/05/05 20:43:54 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(char **all_map, char *map)
{
	int	charsline;
	int	lines;

	charsline = lines_number(map, 'c');
	lines = lines_number(map, 'l');
	if (lines <= 2 || (charsline - 1) <= 2)
		error_cases("Map to small");
	if (lines == charsline - 1)
		error_cases("Map to small");
	check_columns(all_map, charsline);
	check_items(all_map);
}

void	only_ones(char *map)
{
	int	i;

	i = 0;
	while (map[i + 1])
	{
		if (map[i] != '1')
			error_cases("The map is not surrounded by borders");
		i++;
	}
}

void	count_chars(char *map, int charsline, int c)
{
	if (c == 2)
	{
		if (map[charsline] != '\0' || map[charsline - 2] != '1')
			error_cases("The map is not a rectangle");
		else if (map[0] != '1')
			error_cases("The map is not surrounded by borders");
	}
	else if (c == 1)
	{
		if (map[charsline - 1] != '\0' || map[charsline - 2] != '1')
			error_cases("The map is not a rectangle");
		only_ones(map);
	}
}

void	check_columns(char **map, int charsline)
{
	int	i;

	i = 0;
	only_ones(map[i]);
	i++;
	while (map[i + 1])
	{
		count_chars(map[i], charsline, 2);
		i++;
	}
	count_chars(map[i], charsline, 1);
}
