/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:22:14 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/01 18:39:21 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void put_images(t_data *data)
{
    int len = 64;

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

// Escribir un píxel en la imagen
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    if (x >= 0 && x < data->win_width && y >= 0 && y < data->win_high)
    {
        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
    }
}

// Dibujar el mapa en la ventana
void draw_map(t_data *data)
{
    int x, y;
    int tile_size = 64; // Tamaño de cada celda en px

    y = 0;
    while (y < data->map.height)
    {
        x = 0;
        while (x < data->map.width)
        {
            int pixel_x = x * tile_size;
            int pixel_y = y * tile_size;

            char c = data->map.grid[y][x];

            // Poner suelo en cada celda
            mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, pixel_x, pixel_y);

            if (c == '1')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall, pixel_x, pixel_y);
            else if (c == 'P')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player, pixel_x, pixel_y);
            else if (c == 'C')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->objects, pixel_x, pixel_y);
            else if (c == 'E')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit, pixel_x, pixel_y);

            x++;
        }
        y++;
    }
}



