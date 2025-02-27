/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:15:46 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/26 20:31:49 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

#define WIDTH 800
#define HEIGHT 900

typedef struct s_game
{
    void    *mlx;
    void    *win;
    void    *background;
    void    *sprite;
    int     bg_width, bg_height;
    int     sprite_width, sprite_height;
}   t_game;

// Funciones principales del juego
void    init_game(t_game *game);
void    load_images(t_game *game);
void    render_game(t_game *game);
void    start_game_loop(t_game *game);
void    clean_exit(t_game *game);
int 	on_destroy(t_game *game);
int		on_keypress(int keycode, t_game *game);

#endif 
