/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:22:14 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/02 10:13:14 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// Cargar imágenes desde archivos XPM
void put_images(t_data *data)
{
    int len = TILE_SIZE;

    data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "textures/wall.xpm", &len, &len);
    data->player = mlx_xpm_file_to_image(data->mlx_ptr, "textures/player.xpm", &len, &len);
    data->floor = mlx_xpm_file_to_image(data->mlx_ptr, "textures/floor.xpm", &len, &len);
    data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "textures/exit.xpm", &len, &len);
    data->objects = mlx_xpm_file_to_image(data->mlx_ptr, "textures/collectible.xpm", &len, &len);

    if (!data->wall || !data->player || !data->floor || !data->exit || !data->objects)
    {
        perror("Error cargando imágenes XPM");
        exit(EXIT_FAILURE);
    }
}

// Calcular las coordenadas en píxeles para dibujar en la ventana
void get_pixel_position(int x, int y, int *pixel_x, int *pixel_y)
{
    *pixel_x = x * TILE_SIZE;
    *pixel_y = y * TILE_SIZE;
}

// Dibujar una imagen específica en una celda del mapa
void draw_tile(t_data *data, char tile, int x, int y)
{
    int pixel_x, pixel_y;

    get_pixel_position(x, y, &pixel_x, &pixel_y);
    
    // Primero dibuja el suelo como base
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, pixel_x, pixel_y);

    if (tile == '1')
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall, pixel_x, pixel_y);
    else if (tile == 'P')
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player, pixel_x, pixel_y);
    else if (tile == 'C')
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->objects, pixel_x, pixel_y);
    else if (tile == 'E')
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit, pixel_x, pixel_y);
}

// Dibujar cada fila del mapa (sin `for`)
void draw_map_row(t_data *data, int y)
{
    int x = 0;

    while (x < data->map.width)
    {
        draw_tile(data, data->map.grid[y][x], x, y);
        x++;
    }
}

// Dibujar el mapa completo (sin `for`)
void draw_map(t_data *data)
{
    int y = 0;

    while (y < data->map.height)
    {
        draw_map_row(data, y);
        y++;
    }
}
