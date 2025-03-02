/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:22:24 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/02 12:43:34 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:22:24 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/02 11:09:16 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	count_collectibles(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.grid[y][x] == 'C')
				data->collectibles++;
			x++;
		}
		y++;
	}
}

void	init_game(t_data *data)
{
	data->collectibles = 0;
	data->moves = 0;
}

int	setup_window(t_data *data)
{
	void	*mlx;
	int		width;
	int		height;

	data->win_width = data->map.width * TILE_SIZE;
	data->win_high = data->map.height * TILE_SIZE;
	data->mlx_ptr = mlx_init();
	mlx = data->mlx_ptr;
	width = data->win_width;
	height = data->win_high;
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(mlx, width, height, "So_long");
	if (!data->win_ptr)
	{
		free(data->mlx_ptr);
		return (1);
	}
	return (0);
}

void	run_game(t_data *data)
{
	put_images(data);
	draw_map(data);
	mlx_key_hook(data->win_ptr, handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 0, x_close, data);
	mlx_loop(data->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_game(&data);
	if (argc != 2)
		return (ft_printf("Uso: %s <archivo.ber>\n", argv[0]), 1);
	if (!load_map(argv[1], &data.map, &data))
		return (ft_printf("Error al cargar el mapa\n"), 1);
	ft_printf("DEBUG: Mapa cargado en memoria:\n");
	count_collectibles(&data);
	check_valid_map(&data);
	if (setup_window(&data))
		return (1);
	run_game(&data);
	free_map(&data.map);
	return (0);
}
