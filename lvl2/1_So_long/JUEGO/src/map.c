/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:23:02 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/02 13:08:38 by alvdelga         ###   ########.fr       */
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

// Eliminar el salto de línea de una línea leída
static	void	remove_newline(char *line, int *len)
{
	if (line[*len - 1] == '\n')
	{
		line[*len - 1] = '\0';
		(*len)--;
	}
}

// Buscar la posición inicial del jugador en el mapa
static	void	find_player_position(t_data *data, char *line, int row)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] == 'P')
		{
			data->player_x = j;
			data->player_y = row;
			return ;
		}
		j++;
	}
}

// Leer y procesar el archivo del mapa
static int	read_map_file(int fd, t_map *map, t_data *data)
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
		find_player_position(data, line, i);
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
		return (perror("Error leyendo mapa"), 0);
	if (!allocate_map_memory(map))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("Error abriendo archivo"), 0);
	if (!read_map_file(fd, map, data))
		return (0);
	close(fd);
	return (1);
}
