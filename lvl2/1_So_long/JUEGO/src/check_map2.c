/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:28:38 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/05 16:00:00 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	check_rectangular(t_map *map, t_data *data)
{
	int	i;
	int	width;
	int	row_length;

	if (map->height < 2)
		error_cases("1 El mapa no es rectangular.", data);
	if (!map->grid || !map->grid[0])
		error_cases("2 El mapa no es rectangular.", data);
	width = ft_strlen(map->grid[0]);
	i = 0;
	row_length = 0;
	while (i < map->height)
	{
		if (!map->grid[i])
			error_cases("3 El mapa no es rectangular.", data);
		row_length = ft_strlen(map->grid[i]);
		if (row_length != width)
			error_cases("4 El mapa no es rectangular.", data);
		i++;
	}
	map->width = width;
}

void	check_invalid_chars(t_map *map, t_data *data)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			tile = map->grid[y][x];
			if (tile != '0' && tile != '1' && tile != 'P'
				&& tile != 'E' && tile != 'C')
				error_cases("El mapa contiene caracteres inválidos.", data);
			x++;
		}
		y++;
	}
}

void	check_borders(t_map *map, t_data *data)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1')
			error_cases("El borde superior no está cerrado", data);
		if (map->grid[map->height - 1][i] != '1')
			error_cases("El borde inferior no está cerrado.", data);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1')
			error_cases("El borde izquierdo no está cerrado.", data);
		if (map->grid[i][map->width - 1] != '1')
			error_cases("El borde derecho no está cerrado.", data);
		i++;
	}
}

// Contar los elementos del mapa y verificar que hay al menos uno de cada
void	count_items(t_map *map, t_data *data, int *counts)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'P')
			{
				counts[0]++;
				if (counts[0] == 1)
					data->player_x = x;
				if (counts[0] == 1)
					data->player_y = y;
			}
			else if (map->grid[y][x] == 'E')
				counts[1]++;
			else if (map->grid[y][x] == 'C')
				counts[2]++;
			x++;
		}
		y++;
	}
}

void	check_items(t_map *map, t_data *data)
{
	int	counts[3];

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	data->player_x = -1;
	data->player_y = -1;
	count_items(map, data, counts);
	if (counts[0] != 1)
		error_cases("El mapa debe contener SOLO un jugador.", data);
	if (counts[1] != 1)
		error_cases("El mapa debe contener exactamente una salida.", data);
	if (counts[2] < 1)
		error_cases("El mapa debe contener al menos un coleccionable.", data);
}
