/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:52:15 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/02 21:40:06 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// Asignar memoria para la matriz del mapa
int	allocate_map_memory(t_map *map)
{
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (perror("Error al asignar memoria"), 0);
	return (1);
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
            free(map->grid[i]);
    }
    free(map->grid);
    map->grid = NULL;
}

void free_images(t_data *data)
{
    if (!data->mlx_ptr)
        return;
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



// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }
