/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:00:00 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/01 19:30:00 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdlib.h>
#include <string.h>

// Verificar si el mapa es rectangular
void check_rectangular(t_map *map)
{
    int i;
    int width = strlen(map->grid[0]);
    
    for (i = 1; i < map->height; i++)
    {
        if ((int)strlen(map->grid[i]) != width)
            error_cases("El mapa no es rectangular");
    }
    map->width = width;
}

// Verificar si el mapa está rodeado de muros
void check_borders(t_map *map)
{
    int i;

    // 🔹 Verificar la primera y última fila
    for (i = 0; i < map->width; i++)
    {
        if (map->grid[0][i] != '1')
            error_cases("Error: El borde superior no está cerrado correctamente.");
        if (map->grid[map->height - 1][i] != '1')
            error_cases("Error: El borde inferior no está cerrado correctamente.");
    }

    // 🔹 Verificar la primera y última columna en cada fila
    for (i = 0; i < map->height; i++)
    {
        int row_length = strlen(map->grid[i]);

        // 🔹 Asegurar que la fila tenga la misma longitud que map->width
        if (row_length != map->width)
        {
            ft_printf("DEBUG: Error en la fila %d. Longitud real: %d (esperado %d)\n", i, row_length, map->width);
            error_cases("Error: El mapa tiene filas de diferentes longitudes.");
        }

        // 🔹 Verificar los bordes izquierdo y derecho
        if (map->grid[i][0] != '1')
            error_cases("Error: El borde izquierdo no está cerrado correctamente.");
        if (map->grid[i][map->width - 1] != '1')  
            error_cases("Error: El borde derecho no está cerrado correctamente.");
    }
}

// Contar los elementos del mapa y verificar que hay al menos uno de cada
void check_items(t_map *map, t_data *data)
{
    int x, y, p_count = 0, e_count = 0, c_count = 0;

    // 🔹 Asegurar que data->collectibles se reinicia antes de contar
    data->collectibles = 0;

    for (y = 0; y < map->height; y++)
    {
        for (x = 0; x < map->width; x++)
        {
            if (map->grid[y][x] == 'P') p_count++;
            if (map->grid[y][x] == 'E') e_count++;
            if (map->grid[y][x] == 'C')
            {
                c_count++;
                data->collectibles++; // 🔹 Contamos correctamente los coleccionables
            }
        }
    }

    // 🔹 Depuración: imprimir los valores contados
    ft_printf("DEBUG: Coleccionables contados -> %d\n", data->collectibles);
    ft_printf("DEBUG: Player -> %d, Exit -> %d\n", p_count, e_count);

    if (p_count != 1 || e_count != 1 || c_count < 1)
        error_cases("El mapa debe contener exactamente un jugador, una salida y al menos un coleccionable");
}

// Algoritmo de Flood Fill para verificar que hay un camino válido
int flood_fill(int y, int x, char **map, int *coins, int *exit_found, int map_width, int map_height)
{
    // 🛑 **Si el Flood Fill toca un borde que no es '1', significa que el mapa está abierto**
    if ((y == 0 || x == 0 || y == map_height - 1 || x == map_width - 1) && map[y][x] != '1')
        error_cases("Error: El mapa tiene una apertura en los bordes.");

    // Si estamos fuera del mapa o en un muro, terminamos
    if (y < 0 || x < 0 || !map[y] || !map[y][x] || map[y][x] == '1' || map[y][x] == 'V')
        return 0;

    // Contamos coleccionables y la salida encontrada
    if (map[y][x] == 'C')
        (*coins)--;
    if (map[y][x] == 'E')
        *exit_found = 1;

    // Marcar la celda como visitada
    map[y][x] = 'V';

    // Explorar en las 4 direcciones
    flood_fill(y + 1, x, map, coins, exit_found, map_width, map_height); // Abajo
    flood_fill(y - 1, x, map, coins, exit_found, map_width, map_height); // Arriba
    flood_fill(y, x + 1, map, coins, exit_found, map_width, map_height); // Derecha
    flood_fill(y, x - 1, map, coins, exit_found, map_width, map_height); // Izquierda

    return (*coins == 0 && *exit_found);
}



// Verificar si el mapa es válido
void check_valid_map(t_data *data)
{
    int x = data->player_x;
    int y = data->player_y;
    int exit_found = 0;
    char **map_copy;

    // Asegurar que usamos correctamente el número de coleccionables
    int coins = data->collectibles;
    if (coins < 1)
        error_cases("Error: No se detectaron coleccionables");

    map_copy = malloc(sizeof(char *) * (data->map.height + 1));
    if (!map_copy)
        error_cases("Error al asignar memoria para el mapa");

    for (int i = 0; i < data->map.height; i++)
    {
        map_copy[i] = strdup(data->map.grid[i]);
        if (!map_copy[i])
            error_cases("Error al duplicar el mapa");
    }
    map_copy[data->map.height] = NULL;

    // Debug antes del Flood Fill
    ft_printf("DEBUG: Posición inicial del jugador -> x: %d, y: %d\n", x, y);
    ft_printf("DEBUG: Coleccionables -> %d\n", coins);
    ft_printf("DEBUG: Mapa copiado antes del Flood Fill:\n");
    for (int i = 0; i < data->map.height; i++)
        ft_printf("%s\n", map_copy[i]);

    // Asegurar que se usa bien `y, x` en el Flood Fill
    if (!flood_fill(y, x, map_copy, &coins, &exit_found, data->map.width, data->map.height))
    error_cases("El mapa no tiene una solución válida");

    // Liberar memoria
    for (int i = 0; i < data->map.height; i++)
        free(map_copy[i]);
    free(map_copy);
}


// Función principal de validación del mapa
void check_map(t_data *data)
{
    check_rectangular(&data->map);
    check_borders(&data->map);
    check_items(&data->map, data);
    check_valid_map(data);
}
