/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:23:40 by miguelgo          #+#    #+#             */
/*   Updated: 2024/05/05 20:50:22 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_atributes(t_atrib *atribs, char **map, char *argv)
{
	atribs->coins = get_coins(map);
	atribs->height = lines_number(argv, 'l');
	atribs->width = lines_number(argv, 'c') - 1;
	atribs->moves = 1;
	atribs->height *= 70;
	atribs->width *= 70;
	atribs->mlx = mlx_init();
	atribs->win = mlx_new_window
		(atribs->mlx, atribs->width, atribs->height, "So_long");
	atribs->escape = 0;
}

int	close_window(t_atrib *atribs)
{
	mlx_destroy_window(atribs->mlx, atribs->win);
	exit (0);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_map	***final_map;
	t_atrib	atribs;

	if (argc != 2)
		error_cases("Incorrect number of arguments");
	if (!ft_strnstr(argv[1], ".ber"))
		error_cases("Introduce a .ber file");
	map = get_map(argv[1]);
	check_map(map, argv[1]);
	final_map = NULL;
	final_map = do_map(map, final_map, argv[1]);
	init_atributes(&atribs, map, argv[1]);
	(**final_map)->player = final_map[go_to_init(map, 'j')]
	[go_to_init(map, 'i')];
	check_valid(map, &atribs);
	atribs.final_map = final_map;
	mlx_hook(atribs.win, 02, 1L, key_handler, &atribs);
	mlx_hook(atribs.win, 17, 1L << 17, close_window, &atribs);
	put_images(&atribs);
	render(final_map, &atribs);
	mlx_loop(atribs.mlx);
}
