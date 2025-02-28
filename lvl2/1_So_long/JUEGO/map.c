/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:23:02 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/28 12:52:16 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "gnl/get_next_line.h"
#include <string.h> // 🔹 Incluir para strlen()

// Función para contar el número de líneas en el archivo
static int count_lines(const char *filename)
{
    int     fd;
    int     lines = 0;
    char    *line;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (-1);
    
    while ((line = get_next_line(fd)))
    {
        lines++;
        free(line);
    }
    close(fd);
    return (lines);
}

// Función para leer el mapa en una matriz
int load_map(const char *filename, t_map *map)
{
    int     fd;
    int     i = 0;
    char    *line;

    map->height = count_lines(filename);
    if (map->height <= 0)
        return (perror("Error leyendo mapa"), 0);

    map->grid = malloc(sizeof(char *) * (map->height + 1));
    if (!map->grid)
        return (perror("Error al asignar memoria"), 0);

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (perror("Error abriendo archivo"), 0);

    map->width = 0;  // 🔹 Inicializar ancho en 0

    while ((line = get_next_line(fd)))
    {
        int len = strlen(line);
        if (line[len - 1] == '\n') // 🔹 Quitar salto de línea si existe
        {
            line[len - 1] = '\0';
            len--;
        }

        map->grid[i] = line;
        
        if (len > map->width)  // 🔹 Buscar la línea más larga
            map->width = len;
        i++;
    }
    map->grid[i] = NULL;
    close(fd);
    return (1);
}



// Liberar memoria del mapa
void free_map(t_map *map)
{
    int i = 0;
    while (map->grid[i])
        free(map->grid[i++]);
    free(map->grid);
}
