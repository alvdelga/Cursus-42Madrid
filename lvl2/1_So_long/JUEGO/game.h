/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:22:40 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/28 11:22:47 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "minilibx-linux/mlx.h"
# include "map.h"

typedef struct s_data {
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     win_width;
    int     win_high;
    t_map   map; // Agregamos el mapa al struct
}   t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color);
void draw_map(t_data *data);

#endif
