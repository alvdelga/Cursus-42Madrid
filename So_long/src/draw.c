/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:22:14 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/02 13:09:46 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// Cargar imágenes desde archivos XPM
void	put_images(t_data *data)
{
	int	len;

	len = TILE_SIZE;
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL, &len, &len);
	data->player = mlx_xpm_file_to_image(data->mlx_ptr, PLA, &len, &len);
	data->floor = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR, &len, &len);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, &len, &len);
	data->objects = mlx_xpm_file_to_image(data->mlx_ptr, OBJECT, &len, &len);
	if (!data->wall || !data->player || !data->floor
		|| !data->exit || !data->objects)
	{
		perror("Error cargando imágenes XPM");
		exit(EXIT_FAILURE);
	}
}

// Calcular las coordenadas en píxeles para dibujar en la ventana
void	get_pixel_position(int x, int y, int *pixel_x, int *pixel_y)
{
	*pixel_x = x * TILE_SIZE;
	*pixel_y = y * TILE_SIZE;
}

// Dibujar una imagen específica en una celda del mapa
void	draw_tile(t_data *data, char tile, int x, int y)
{
	int		pixel_x;
	int		pixel_y;
	void	*img;

	get_pixel_position(x, y, &pixel_x, &pixel_y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor,
		pixel_x, pixel_y);
	img = NULL;
	if (tile == '1')
		img = data->wall;
	else if (tile == 'P')
		img = data->player;
	else if (tile == 'C')
		img = data->objects;
	else if (tile == 'E')
		img = data->exit;
	if (img)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img, pixel_x, pixel_y);
}

// Dibujar cada fila del mapa (sin `for`)
void	draw_map_row(t_data *data, int y)
{
	int	x;

	x = 0;
	while (x < data->map.width)
	{
		draw_tile(data, data->map.grid[y][x], x, y);
		x++;
	}
}

// Dibujar el mapa completo (sin `for`)
void	draw_map(t_data *data)
{
	int	y;

	y = 0;
	while (y < data->map.height)
	{
		draw_map_row(data, y);
		y++;
	}
}
