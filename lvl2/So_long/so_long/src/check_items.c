/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:36:53 by miguelgo          #+#    #+#             */
/*   Updated: 2024/05/02 12:21:14 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_items(char **all_map)
{
	int	i;
	int	j;
	int	exits;
	int	coins;
	int	position;

	exits = 0;
	coins = 0;
	position = 0;
	j = 0;
	while (all_map[j])
	{
		i = 0;
		while (all_map[j][i])
		{
			check_items2(all_map[j][i], &exits, &coins, &position);
			i++;
		}
		j++;
	}
	check_items3(exits, coins, position);
}

void	check_items2(char map_item, int *exits, int *coins, int *position)
{
	if (map_item == 'E')
		(*exits)++;
	else if (map_item == 'P')
		(*position)++;
	else if (map_item == 'C')
		(*coins)++;
	else if (map_item != '1' && map_item != '0' && map_item != '\n')
		error_cases("Caracter no valido en el mapa");
}

void	check_items3(int exits, int coins, int position)
{
	if (exits != 1)
		error_cases("Tiene que haber solo una salida");
	if (coins < 1)
		error_cases("Tiene que haber al menos un consumible");
	if (position != 1)
		error_cases("Tiene que haber solo una posicion inicial");
}

int	get_coins(char **map)
{
	int	i;
	int	j;
	int	coins;

	coins = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				coins++;
			i++;
		}
		j++;
	}
	return (coins);
}
