/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:22:14 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/28 11:22:16 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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
    int tile_size = 50; // Tamaño de cada celda

    for (y = 0; y < data->map.height; y++)
    {
        for (x = 0; x < data->map.width; x++)
        {
            int pixel_x = x * tile_size;
            int pixel_y = y * tile_size;
            int color;

            if (data->map.grid[y][x] == '1')
                color = 0xFFFFFF; // Blanco para las paredes
            else if (data->map.grid[y][x] == 'P')
                color = 0x00FF00; // Verde para el jugador
            else if (data->map.grid[y][x] == 'C')
                color = 0xFFFF00; // Amarillo para coleccionables
            else if (data->map.grid[y][x] == 'E')
                color = 0xFF0000; // Rojo para la salida
            else
                color = 0x000000; // Negro para el suelo

            for (int i = 0; i < tile_size; i++)
            {
                for (int j = 0; j < tile_size; j++)
                    my_mlx_pixel_put(data, pixel_x + j, pixel_y + i, color);
            }
        }
    }
}
