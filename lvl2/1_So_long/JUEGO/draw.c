/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:22:14 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/28 12:47:37 by alvdelga         ###   ########.fr       */
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

    y = 0;
    while (y < data->map.height)
    {
        x = 0;
        while (x < data->map.width)
        {
            // Verificar que el índice está dentro de los límites del mapa
            if (!data->map.grid[y] || x >= (int)strlen(data->map.grid[y]))
            {
                x++;
                continue;  // Saltar espacios vacíos
            }

            int pixel_x = x * tile_size;
            int pixel_y = y * tile_size;
            int color;

            if (data->map.grid[y][x] == '1')
                color = 0x8B4513; // Marrón para las paredes
            else if (data->map.grid[y][x] == 'P')
                color = 0x00FF00; // Verde para el jugador
            else if (data->map.grid[y][x] == 'C')
                color = 0xFFFF00; // Amarillo para coleccionables
            else if (data->map.grid[y][x] == 'E')
                color = 0xFF0000; // Rojo para la salida
            else
                color = 0x000000; // Negro para el suelo

            int i = 0;
            while (i < tile_size)
            {
                int j = 0;
                while (j < tile_size)
                {
                    my_mlx_pixel_put(data, pixel_x + j, pixel_y + i, color);
                    j++;
                }
                i++;
            }
            x++;
        }
        y++;
    }
}


