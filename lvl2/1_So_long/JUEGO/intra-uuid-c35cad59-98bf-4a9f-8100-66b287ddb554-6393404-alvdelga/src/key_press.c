/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 09:50:44 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/05 16:08:50 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	detect_movement(int keysym, int *new_x, int *new_y)
{
	if (keysym == 119 || keysym == 65362)
		(*new_y)--;
	else if (keysym == 115 || keysym == 65364)
		(*new_y)++;
	else if (keysym == 97 || keysym == 65361)
		(*new_x)--;
	else if (keysym == 100 || keysym == 65363)
		(*new_x)++;
}

void	handle_exit(int keysym, t_data *data)
{
	if (keysym == 65307)
	{
		game_over_banner(data);
		free_images(data);
		close_x_connection(data->mlx_ptr);
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free_map(&data->map);
		exit(0);
	}
}

// Verifica si el movimiento es válido y actualiza datos del jugador
int	validate_and_move(t_data *data, int new_x, int new_y)
{
	if (data->map.grid[new_y][new_x] == '1')
		return (0);
	if ((new_x != data->player_x || new_y != data->player_y)
		&& (data->map.grid[new_y][new_x] != 'E'))
		data->moves++;
	if (data->map.grid[new_y][new_x] == 'C')
		data->collectibles--;
	else if (data->map.grid[new_y][new_x] == 'E')
	{
		if (data->collectibles != 0)
		{
			ft_printf("[!] Recoge todos los coleccionables [!]\n");
			return (0);
		}
		data->moves++;
		game_over_banner(data);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	return (1);
}

void	update_player_position(t_data *data, int new_x, int new_y)
{
	data->map.grid[data->player_y][data->player_x] = '0';
	data->map.grid[new_y][new_x] = 'P';
	data->player_x = new_x;
	data->player_y = new_y;
	ft_printf("[+] Movimientos: %d [+] Queda %d Coleccionable!\n",
		data->moves, data->collectibles);
	draw_map(data);
}

int	handle_keypress(int keysym, t_data *data)
{
	int	new_x;
	int	new_y;

	new_y = data->player_y;
	new_x = data->player_x;
	detect_movement(keysym, &new_x, &new_y);
	handle_exit(keysym, data);
	if (validate_and_move(data, new_x, new_y))
		update_player_position(data, new_x, new_y);
	return (0);
}
