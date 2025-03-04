/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:00:00 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/04 13:49:06 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdlib.h>
#include <string.h>

// Verificar si el mapa es rectangular
void check_rectangular(t_map *map, t_data *data)
{
    int i;
    
    if (map->height < 2)
        error_cases("Error: El mapa no es rectangular.", data);

    int width = strlen(map->grid[0]);

    ft_printf("DEBUG: Entrando en check_rectangular()\n");
    ft_printf("DEBUG: Ancho esperado del mapa: %d\n", width);

    for (i = 1; i < map->height; i++)
    {
        if (!map->grid[i])
            error_cases("Error: El mapa no es rectangular.", data);

        ft_printf("DEBUG: Fila %d tiene %d caracteres\n", i, (int)strlen(map->grid[i]));
        
        if ((int)strlen(map->grid[i]) != width)
            error_cases("Error: El mapa no es rectangular.", data);
    }
    map->width = width;
}

// Validar solo los caracteres antes de cualquier otra verificación
void check_invalid_chars(t_map *map, t_data *data)
{
    int x, y;

    ft_printf("DEBUG: Entrando en check_invalid_chars() - Validando caracteres\n");

    for (y = 0; y < map->height; y++)
    {
        for (x = 0; x < map->width; x++)
        {
            char tile = map->grid[y][x];

            if (tile != '0' && tile != '1' && tile != 'P' && tile != 'E' && tile != 'C')
                error_cases("Error: El mapa contiene caracteres inválidos.", data);
        }
    }
}

// Verificar si el mapa está rodeado de muros
void check_borders(t_map *map, t_data *data)
{
    int i;

    ft_printf("DEBUG: Entrando en check_borders()\n");

    for (i = 0; i < map->width; i++)
    {
        if (map->grid[0][i] != '1')
            error_cases("Error: El borde superior no está cerrado correctamente.", data);
        if (map->grid[map->height - 1][i] != '1')
            error_cases("Error: El borde inferior no está cerrado correctamente.", data);
    }

    for (i = 0; i < map->height; i++)
    {
        if (map->grid[i][0] != '1')
            error_cases("Error: El borde izquierdo no está cerrado correctamente.", data);
        if (map->grid[i][map->width - 1] != '1')  
            error_cases("Error: El borde derecho no está cerrado correctamente.", data);
    }
}

// Contar los elementos del mapa y verificar que hay al menos uno de cada
void check_items(t_map *map, t_data *data)
{
    int x, y, p_count = 0, e_count = 0, c_count = 0;

    ft_printf("DEBUG: Entrando en check_items() - Validación de elementos P, E, C\n");

    // Reiniciar las coordenadas del jugador
    data->player_x = -1;
    data->player_y = -1;

    for (y = 0; y < map->height; y++)
    {
        for (x = 0; x < map->width; x++)
        {
            char tile = map->grid[y][x];

            if (tile == 'P')
            {
                p_count++;  // Contar los jugadores
                if (p_count == 1) // Guardar la posición del jugador solo la primera vez
                {
                    data->player_x = x;
                    data->player_y = y;

                    // Imprimir las coordenadas del jugador
                    ft_printf("DEBUG: Player position: (%d, %d)\n", data->player_x, data->player_y);  // Ver las coordenadas del jugador
                }
            }
            else if (tile == 'E') e_count++;  // Contar las salidas
            else if (tile == 'C') c_count++;  // Contar los coleccionables
        }
    }

    // Imprimir el número de jugadores encontrados
    ft_printf("DEBUG: P count: %d\n", p_count);  // Imprimir el número de jugadores

    // Validar que solo haya un jugador
    if (p_count != 1)
        error_cases("Error: El mapa debe contener SOLO un jugador.", data);
    
    // Validar que solo haya una salida
    if (e_count != 1)
        error_cases("Error: El mapa debe contener exactamente una salida.", data);

    // Validar que haya al menos un coleccionable
    if (c_count < 1)
        error_cases("Error: El mapa debe contener al menos un coleccionable.", data);
}




// Algoritmo de Flood Fill para verificar que hay un camino válido
int flood_fill(int y, int x, char **map, int *coins, int *exit_found, int map_width, int map_height)
{
	if ((y == 0 || x == 0 || y == map_height - 1
			|| x == map_width - 1) && map[y][x] != '1')
		error_cases("Error: El mapa tiene una apertura en los bordes.", NULL);
	if (y < 0 || x < 0 || !map[y] || !map[y][x]
		|| map[y][x] == '1' || map[y][x] == 'V')
		return (0);
	if (map[y][x] == 'C')
		(*coins)--;
	if (map[y][x] == 'E')
		*exit_found = 1;
	map[y][x] = 'V';
	flood_fill(y + 1, x, map, coins, exit_found, map_width, map_height);
	flood_fill(y - 1, x, map, coins, exit_found, map_width, map_height);
	flood_fill(y, x + 1, map, coins, exit_found, map_width, map_height);
	flood_fill(y, x - 1, map, coins, exit_found, map_width, map_height);
	return (*coins == 0 && *exit_found);
}

// Verificar si el mapa es válido
void check_valid_map(t_data *data)
{
	int coins;
	int exit_found;
	char **map_copy;
	int i;

	exit_found = 0;
	coins = data->collectibles;
	i = 0;
	ft_printf("DEBUG: Entrando en check_valid_map()\n");
	if (coins < 1)
		error_cases("Error: No se detectaron coleccionables", data);

	map_copy = malloc(sizeof(char *) * (data->map.height + 1));
	if (!map_copy)
		error_cases("Error al asignar memoria para el mapa", data);
	while (i < data->map.height)
	{
		map_copy[i] = strdup(data->map.grid[i]);
		if (!map_copy[i])
		{
			error_cases("Error al duplicar el mapa", data);
		}
		i++;
	}
	map_copy[data->map.height] = NULL;
	if (!flood_fill(data->player_y, data->player_x, map_copy, &coins, &exit_found, data->map.width, data->map.height))
	{
		for (i = 0; i < data->map.height; i++)
		{
			free(map_copy[i]);
		}
		free(map_copy);
		error_cases("Error: El mapa no tiene una solución válida", data);
	}
	for (i = 0; i < data->map.height; i++)
	{
		free(map_copy[i]);
	}
	free(map_copy);
}

// Función principal de validación del mapa
void check_map(t_data *data)
{
	ft_printf("DEBUG: Entrando en check_map()\n");
	check_rectangular(&data->map, data);
	check_invalid_chars(&data->map, data);
	check_borders(&data->map, data);
	check_items(&data->map, data);
	check_valid_map(data);
}
