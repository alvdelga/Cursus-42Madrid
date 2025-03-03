/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:52:15 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/03 18:52:49 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// Asignar memoria para la matriz del mapa
int allocate_map_memory(t_map *map)
{
    // Asigna memoria para las filas del mapa
    map->grid = malloc(sizeof(char *) * (map->height + 1));
    if (!map->grid)
    {
        perror("Error al asignar memoria");
        return 0;
    }

    // Inicializa las filas a NULL
    for (int i = 0; i < map->height; i++)
    {
        map->grid[i] = NULL;
    }

    map->grid[map->height] = NULL; // Marca el final de la matriz
    return 1;
}


// Liberar memoria del mapa
void free_map(t_map *map)
{
    int i;

    if (!map || !map->grid)
        return;
    for (i = 0; i < map->height; i++)
    {
        if (map->grid[i])
            free(map->grid[i]);  // ✅ Liberar cada fila del mapa
    }
    free(map->grid);  // ✅ Luego liberar el array de punteros
    map->grid = NULL;
}


void free_images(t_data *data)
{
    if (data->mlx_ptr)
    {
        if (data->wall)
            mlx_destroy_image(data->mlx_ptr, data->wall);
        if (data->player)
            mlx_destroy_image(data->mlx_ptr, data->player);
        if (data->floor)
            mlx_destroy_image(data->mlx_ptr, data->floor);
        if (data->exit)
            mlx_destroy_image(data->mlx_ptr, data->exit);
        if (data->objects)
            mlx_destroy_image(data->mlx_ptr, data->objects);
    }
}


// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }
