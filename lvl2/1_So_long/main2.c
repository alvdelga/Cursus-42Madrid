/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:16:38 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/26 18:47:10 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_game(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        printf("Error: No se pudo inicializar MiniLibX\n");
        exit(1);
    }
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Fondo + Imagen");
}

void load_images(t_game *game)
{
    game->background = mlx_xpm_file_to_image(game->mlx, "fondo.xpm", &game->bg_width, &game->bg_height);
    if (!game->background)
    {
        printf("Error: No se pudo cargar la imagen de fondo\n");
        exit(1);
    }

    game->sprite = mlx_xpm_file_to_image(game->mlx, "player.xpm", &game->sprite_width, &game->sprite_height);
    if (!game->sprite)
    {
        printf("Error: No se pudo cargar la imagen superior\n");
        exit(1);
    }
}

void render_game(t_game *game)
{
    mlx_put_image_to_window(game->mlx, game->win, game->background, 0, 0);
    mlx_put_image_to_window(game->mlx, game->win, game->sprite, 300, 200);
}

void start_game_loop(t_game *game)
{
    mlx_loop(game->mlx);
}

int main(void)
{
    t_game game;

    init_game(&game);
    load_images(&game);
    render_game(&game);
    start_game_loop(&game);
    //clean_exit(&game);
    return (0);
}