/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:04:45 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/03 18:37:35 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <X11/Xlib.h>
# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include "../minilibx-linux/mlx.h"

# define TILE_SIZE 64

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

# define RST         "\033[0m"
# define SLOW_BLINK  "\033[5m"
# define BOLD        "\033[1m"

// Colores de texto
# define F_L_YELLOW  "\033[1;33m"
# define F_L_GREY    "\033[1;37m"
# define F_L_MAGENTA "\033[1;35m"
# define RED  "\033[1;31m"
# define CIAN    "\033[1;36m"
# define BLUE "\033[1;34m"

# define PLA "./sprites/player_rr.xpm"
# define FLOOR "./sprites/floor.xpm"
# define WALL "./sprites/wall.xpm"
# define OBJECT "./sprites/collectible.xpm"
# define EXIT "./sprites/exit.xpm"

# include <fcntl.h>  // open()
# include <unistd.h> // read(), close()
# include <stdlib.h> // malloc(), free()
# include <stdio.h>  // perror()
# include <string.h> // strlen()

// 🔹 Definir la estructura del mapa una sola vez
typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

// 🔹 Definir la estructura principal del juego
typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		win_width;
	int		win_high;
	t_map	map;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
	// 🔹 Agregar imágenes XPM
	void	*wall;
	void	*player;
	void	*floor;
	void	*exit;
	void	*objects;
}	t_data;

// 🔹 Declaraciones de funciones
int		load_map(const char *filename, t_map *map, t_data *data);
void	free_map(t_map *map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_map(t_data *data);
void	game_over_banner(t_data *data);
void	put_images(t_data *data);
void	check_valid_map(t_data *data);
void	check_rectangular(t_map *map, t_data *data);
void	check_borders(t_map *map, t_data *data);
void	check_items(t_map *map, t_data *data);
void	error_cases(const char *msg, t_data *data);
void	check_map(t_data *data);
int		flood_fill(int y, int x, char **map, int *coins,
			int *exit_found, int map_width, int map_height);
int		x_close(t_data *data);
int		handle_keypress(int keysym, t_data *data);
void	free_map(t_map *map);
int		allocate_map_memory(t_map *map);
void	free_images(t_data *data);
void close_x_connection(void *mlx_ptr);

#endif
