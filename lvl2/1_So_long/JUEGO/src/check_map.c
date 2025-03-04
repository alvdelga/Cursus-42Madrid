/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:00:00 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/04 17:29:05 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	flood_fill(int y, int x, t_flood_fill *data)
{
	if ((y == 0 || x == 0 || y == data->height - 1
			|| x == data->width - 1) && data->map[y][x] != '1')
		error_cases("Error: El mapa tiene una apertura en los bordes.", NULL);
	if (y < 0 || x < 0 || !data->map[y] || !data->map[y][x]
		|| data->map[y][x] == '1' || data->map[y][x] == 'V')
		return (0);
	if (data->map[y][x] == 'C')
		(*data->coins)--;
	if (data->map[y][x] == 'E')
		*data->exit_found = 1;
	data->map[y][x] = 'V';
	flood_fill(y + 1, x, data);
	flood_fill(y - 1, x, data);
	flood_fill(y, x + 1, data);
	flood_fill(y, x - 1, data);
	return (*data->coins == 0 && *data->exit_found);
}

char	**allocate_map_copy(t_data *data)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (data->map.height + 1));
	if (!map_copy)
		error_cases("Error al asignar memoria para el mapa", data);
	i = 0;
	while (i < data->map.height)
	{
		map_copy[i] = strdup(data->map.grid[i]);
		if (!map_copy[i])
		{
			free_map_copy(map_copy, i);
			error_cases("Error al duplicar el mapa", data);
		}
		i++;
	}
	map_copy[data->map.height] = NULL;
	return (map_copy);
}

void	free_map_copy(char **map_copy, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(map_copy[i++]);
	free(map_copy);
}

void	check_valid_map(t_data *data)
{
	int				coins;
	int				exit_found;
	t_flood_fill	flood_data;
	char			**map_copy;

	exit_found = 0;
	coins = data->collectibles;
	ft_printf("DEBUG: Entrando en check_valid_map()\n");
	if (coins < 1)
		error_cases("Error: No se detectaron coleccionables", data);
	map_copy = allocate_map_copy(data);
	flood_data = (t_flood_fill){map_copy, &coins, &exit_found,
		data->map.width, data->map.height};
	if (!flood_fill(data->player_y, data->player_x, &flood_data))
	{
		free_map_copy(map_copy, data->map.height);
		error_cases("Error: El mapa no tiene una solución válida", data);
	}
	free_map_copy(map_copy, data->map.height);
}

void	check_map(t_data *data)
{
	ft_printf("DEBUG: Entrando en check_map()\n");
	check_rectangular(&data->map, data);
	check_invalid_chars(&data->map, data);
	check_borders(&data->map, data);
	check_items(&data->map, data);
	check_valid_map(data);
}
