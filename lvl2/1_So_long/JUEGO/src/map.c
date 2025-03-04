/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:23:02 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/04 08:13:22 by alvdelga         ###   ########.fr       */
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
static int find_player_position(t_data *data, char *line, int row)
{
    int j = 0;
    
    while (line[j])
    {
        if (line[j] == 'P')
        {
            if (data->player_x != -1 || data->player_y != -1)
            {
				return 0;  // Retorna 0 si hay múltiples posiciones de jugador
            }
            data->player_x = j;
            data->player_y = row;
        }
        j++;
    }
    return 1;  // Retorna 1 si todo está bien
}


// Leer y procesar el archivo del mapa
static int read_map_file(int fd, t_map *map, t_data *data)
{
    char *line;
    int i;
    int len;

    i = 0;
    map->width = 0;
    line = get_next_line(fd);

	if (!line)
	{
		free(line);
	}
    
    while (line)
    {
        len = ft_strlen(line);
        remove_newline(line, &len);
        
        map->grid[i] = line;
        
        // Llamada para verificar la posición del jugador
        if (!find_player_position(data, line, i))
        {
			
        	//free(line);
            error_cases("Error: Múltiples posiciones de jugador en el mapa.", data);
        }

        if (len > map->width)
            map->width = len;
        
        i++;
        line = get_next_line(fd);
    }

    map->grid[i] = NULL; // Marca el final de la matriz
    return 1;
}


// Función principal para cargar el mapa desde el archivo
int load_map(const char *filename, t_map *map, t_data *data)
{
    int fd;

    map->height = count_lines(filename);
    if (map->height <= 0)
    {
        error_cases("Error leyendo mapa", data);  // Si no se puede contar las líneas, llamar a error_cases
    }

    if (!allocate_map_memory(map))
    {
        error_cases("Error al asignar memoria para el mapa", data);  // Si no se puede asignar memoria para el mapa, llamar a error_cases
    }

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        error_cases("Error abriendo archivo", data);  // Si no se puede abrir el archivo, llamar a error_cases
    }

    if (!read_map_file(fd, map, data))
    {
        // Si la lectura falla (por ejemplo, múltiples jugadores), liberamos la memoria
        free_map(map);  // Liberamos la memoria previamente asignada
        close(fd);  // Asegúrate de cerrar el archivo
        error_cases("Error leyendo el archivo del mapa", data);  // Llamamos a error_cases
    }

    close(fd);  // Asegúrate de cerrar el archivo

    return 1;  // Todo salió bien
}



