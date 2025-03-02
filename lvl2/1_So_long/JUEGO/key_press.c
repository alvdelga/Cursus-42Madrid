/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 09:50:44 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/02 10:05:01 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// Detecta la dirección del movimiento según la tecla presionada
void detect_movement(int keysym, int *new_x, int *new_y)
{
    if (keysym == 119 || keysym == 65362) // W o Flecha Arriba
        (*new_y)--;
    else if (keysym == 115 || keysym == 65364) // S o Flecha Abajo
        (*new_y)++;
    else if (keysym == 97 || keysym == 65361) // A o Flecha Izquierda
        (*new_x)--;
    else if (keysym == 100 || keysym == 65363) // D o Flecha Derecha
        (*new_x)++;
}

// Maneja la salida del juego si se presiona ESC
void handle_exit(int keysym, t_data *data)
{
    if (keysym == 65307) // ESC
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(0);
    }
}

// Verifica si el movimiento es válido y actualiza datos del jugador
int validate_and_move(t_data *data, int new_x, int new_y)
{
    if (data->map.grid[new_y][new_x] == '1') // Pared
        return (0);

    if (new_x != data->player_x || new_y != data->player_y)
        data->moves++;

    if (data->map.grid[new_y][new_x] == 'C') // Coleccionable
        data->collectibles--;
    else if (data->map.grid[new_y][new_x] == 'E') // Salida
    {
        if (data->collectibles != 0)
        {
            ft_printf("Error: Debes recoger todos los coleccionables antes de salir\n");
            return (0);
        }
        game_over_banner();
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(0);
    }

    return (1);
}

// Actualiza la posición del jugador en el mapa
void update_player_position(t_data *data, int new_x, int new_y)
{
    data->map.grid[data->player_y][data->player_x] = '0'; // Vaciar la posición anterior
    data->map.grid[new_y][new_x] = 'P'; // Colocar al jugador en la nueva posición
    data->player_x = new_x;
    data->player_y = new_y;

    // Mostrar información en consola
    ft_printf("Movimientos: %d\n", data->moves);
    printf("Coleccionables: %d\n", data->collectibles);

    // Redibujar el mapa
    draw_map(data);
}

// Función principal que maneja la entrada de teclas
int handle_keypress(int keysym, t_data *data)
{
    int new_x = data->player_x;
    int new_y = data->player_y;

    detect_movement(keysym, &new_x, &new_y);
    handle_exit(keysym, data);

    if (validate_and_move(data, new_x, new_y))
        update_player_position(data, new_x, new_y);

    return (0);
}


/*
int handle_keypress(int keysym, t_data *data)
{
    int new_x = data->player_x;
    int new_y = data->player_y;

    // Detectar teclas de movimiento
    if (keysym == 119 || keysym == 65362) // W o Flecha Arriba
        new_y--;
    else if (keysym == 115 || keysym == 65364) // S o Flecha Abajo
        new_y++;
    else if (keysym == 97 || keysym == 65361) // A o Flecha Izquierda
        new_x--;
    else if (keysym == 100 || keysym == 65363) // D o Flecha Derecha
        new_x++;
    else if (keysym == 65307) // ESC para salir
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(0);
    }

    // Verificar si el movimiento es válido (no chocar con '1')
    if (data->map.grid[new_y][new_x] != '1')
    {
        // Si el jugador realmente se mueve, incrementar el contador
        if (new_x != data->player_x || new_y != data->player_y)
            data->moves++;

        // Si hay un coleccionable, disminuir el contador
        if (data->map.grid[new_y][new_x] == 'C')
            data->collectibles--;
        else if (data->map.grid[new_y][new_x] == 'E' && data->collectibles != 0)
        {
            ft_printf("Error: Debes recoger todos los coleccionables antes de salir\n");
            return (0);
        }
        else if (data->map.grid[new_y][new_x] == 'E' && data->collectibles == 0)
        {
            game_over_banner();
            mlx_destroy_window(data->mlx_ptr, data->win_ptr);
            exit(0);
        }

        // Mover al jugador
        data->map.grid[data->player_y][data->player_x] = '0'; // Vaciar la posición anterior
        data->map.grid[new_y][new_x] = 'P'; // Colocar al jugador en la nueva posición
        data->player_x = new_x;
        data->player_y = new_y;

        // Mostrar movimientos en consola
        ft_printf("Movimientos: %d\n", data->moves);
        printf("Coleccionables: %d\n", data->collectibles);

        // Redibujar el mapa con imágenes XPM
        draw_map(data);
    }

    return (0);
}
*/