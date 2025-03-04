/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:23:02 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/04 13:10:29 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// Contar el número de líneas en el archivo del mapa
static	int	count_lines(const char *filename)
{
	int		fd;
	int		lines;
	char	*line;

	lines = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

static int	read_map_file(int fd, t_map *map)
{
	char	*line;
	int		i;
	int		len;

	i = 0;
	map->width = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		remove_newline(line, &len);
		map->grid[i] = line;
		if (len > map->width)
			map->width = len;
		i++;
		line = get_next_line(fd);
	}
	map->grid[i] = NULL;
	return (1);
}

// Función principal para cargar el mapa desde el archivo
int	load_map(const char *filename, t_map *map, t_data *data)
{
	int	fd;

	map->height = count_lines(filename);
	if (map->height <= 0)
		error_cases("Error leyendo mapa", data);
	if (!allocate_map_memory(map))
		error_cases("Error al asignar memoria para el mapa", data);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_cases("Error abriendo archivo", data);
	if (!read_map_file(fd, map))
	{
		free_map(map);
		close(fd);
		error_cases("Error leyendo el archivo del mapa", data);
	}
	close(fd);
	return (1);
}
