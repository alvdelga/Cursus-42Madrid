#ifndef GAME_H
# define GAME_H

# include "minilibx-linux/mlx.h"
# include <fcntl.h>  // open()
# include <unistd.h> // read(), close()
# include <stdlib.h> // malloc(), free()
# include <stdio.h>  // perror()

// 🔹 Definir la estructura del mapa una sola vez
typedef struct s_map {
    char    **grid;   // Matriz para almacenar el mapa
    int     width;    // Ancho del mapa
    int     height;   // Alto del mapa
}   t_map;

// 🔹 Definir la estructura principal del juego
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
    int     player_x;
    int     player_y;
    int     collectibles;
    int     moves;
}   t_data;

// 🔹 Declaraciones de funciones
int  load_map(const char *filename, t_map *map);
void free_map(t_map *map);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
void draw_map(t_data *data);

#endif
