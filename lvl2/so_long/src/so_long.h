/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:30:39 by miguelgo          #+#    #+#             */
/*   Updated: 2024/05/05 21:03:18 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"

# define BART "./sprites/player.xpm"
# define FLOOR "./sprites/floor.xpm"
# define WALL "./sprites/wall.xpm"
# define OBJECT "./sprites/object.xpm"
# define EXIT "./sprites/exit.xpm"

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

typedef struct s_map
{
	char			content;
	struct s_map	*up;
	struct s_map	*down;
	struct s_map	*right;
	struct s_map	*left;
	struct s_map	*player;

}	t_map;

typedef struct s_atrib
{
	t_map	***final_map;
	t_img	*objects;
	t_img	*player;
	t_img	*floor;
	t_img	*wall;
	t_img	*exit;
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		coins;
	int		moves;
	int		escape;
	int		coins_found;
	int		exit_found;
}	t_atrib;

void	error_cases(char *str);
char	**get_map(char *map);
char	*ft_strnstr(char *haystack, char *needle);
int		lines_number(char *mapa, char c);
void	check_map(char **all_map, char *map);
void	check_columns(char **map, int charsline);
void	count_chars(char *map, int charsline, int c);
void	only_ones(char *map);
void	check_items(char **all_map);
void	check_items2(char map_item, int *exits, int *coins, int *position);
void	check_items3(int exits, int coins, int position);
t_map	***do_map(char **map, t_map ***final_map, char *argv);
t_map	*create_node(char content);
void	link_map(t_map ***final_map, char **map, char *argv);
void	check_valid(char **all_map, t_atrib *atribs);
int		go_to_init(char **all_map, char c);
void	init_atributes(t_atrib *atribs, char **map, char *argv);
int		get_coins(char **map);
void	put_images(t_atrib *atribs);
void	render(t_map ***final_map, t_atrib *atribs);
void	put_visual(int i, int j, char c, t_atrib *atribs);
int		close_window(t_atrib *atribs);
void	move_bart(t_map ***final_map, char c, t_atrib *atribs);
int		key_handler(int keycode, t_atrib *atribs);
void	move_bart2(t_map ***final_map, t_atrib *atribs);
void	print_moves(int a, t_atrib *atribs);
void	victory(void);
int		ft_floodfill_coins(int x, int y, char **all_map, t_atrib *atribs);

#endif