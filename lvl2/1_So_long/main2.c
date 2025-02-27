/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:16:38 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/26 20:31:45 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>

void clean_exit(t_game *game)
{
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    printf("Juego cerrado correctamente.\n");
    exit(0);
}

int on_destroy(t_game *game)
{
    clean_exit(game);
    return (0);
}

int on_keypress(int keycode, t_game *game)
{
    printf("Tecla presionada: %d\n", keycode);

    if (keycode == XK_Escape) // Código de tecla ESC en X11 (Linux)
    {
        printf("ESC detectado! Cerrando el juego...\n");
        clean_exit(game);
    }
    return (0);
}

void init_game(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        printf("Error: No se pudo inicializar MiniLibX\n");
        exit(1);
    }
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Fondo + Imagen");
    if (!game->win)
    {
        printf("Error: No se pudo crear la ventana\n");
        free(game->mlx);
        exit(1);
    }
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
    mlx_hook(game->win, KeyRelease, KeyReleaseMask, on_keypress, game);  // Captura teclas
    mlx_hook(game->win, DestroyNotify, StructureNotifyMask, on_destroy, game);  // Cierra con la cruz
    mlx_loop(game->mlx);
}

int main(void)
{
    t_game game;

    init_game(&game);
    load_images(&game);
    render_game(&game);
    start_game_loop(&game);

    return (0);
}
