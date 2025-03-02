/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:22:24 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/02 10:17:27 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void count_collectibles(t_data *data)
{
    int y = 0;
    
    while (y < data->map.height)
    {
        int x = 0;
        while (x < data->map.width)
        {
            if (data->map.grid[y][x] == 'C')
                data->collectibles++;  
            x++;
        }
        y++;
    }
}
void init_game(t_data *data)
{
    data->collectibles = 0;
    data->moves = 0;
}

int setup_window(t_data *data)
{
    data->win_width = data->map.width * TILE_SIZE; // Cada celda es de 64px
    data->win_high = data->map.height * TILE_SIZE;
    data->mlx_ptr = mlx_init();
    if (!data->mlx_ptr)
        return (1);
    data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width, data->win_high, "Mi Juego");
    return (!data->win_ptr) ? (free(data->mlx_ptr), 1) : 0;
}

void run_game(t_data *data)
{
    put_images(data);
    draw_map(data);

    mlx_key_hook(data->win_ptr, handle_keypress, data); // Manejo de teclas
    mlx_hook(data->win_ptr, 17, 0, x_close, data); // Manejo del cierre de ventana

    mlx_loop(data->mlx_ptr);
}


int main(int argc, char **argv)
{
    t_data data;

    init_game(&data); // Inicializar variables
    if (argc != 2)
        return (ft_printf("Uso: %s <archivo.ber>\n", argv[0]), 1);
    if (!load_map(argv[1], &data.map, &data)) // Cargar el mapa desde el archivo .ber
        return (ft_printf("Error al cargar el mapa\n"), 1);
    count_collectibles(&data);  // Contar coleccionables
    check_valid_map(&data);     // Verificar si el mapa es válido
    if (setup_window(&data))    // Configurar ventana y MiniLibX
        return (1);
    run_game(&data);            // Iniciar el bucle del juego
    free_map(&data.map);        // Liberar memoria del mapa al salir
    return (0);
}


/*int main(int argc, char **argv)
{
    t_data  data;
	data.collectibles = 0;
	data.moves = 0;

	int y = 0;
    if (argc != 2)
        return (ft_printf("Uso: %s <archivo.ber>\n", argv[0]), 1);
    // Cargar el mapa desde el archivo .ber
    if (!load_map(argv[1], &data.map, &data)) // Pasamos &data para capturar player_x y player_y
        return (ft_printf("Error al cargar el mapa\n"), 1);
	// Contar coleccionables
    count_collectibles(&data);
	// Verificar si el mapa es válido
	check_valid_map(&data);
    // Configurar ventana según el tamaño del mapa
    data.win_width = data.map.width * 64; // Cada celda es de 50px
    data.win_high = data.map.height * 64;
    // Inicializar MiniLibX
    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (1);
    // Crear una ventana
    data.win_ptr = mlx_new_window(data.mlx_ptr, data.win_width, data.win_high, "Mi Juego");
    if (!data.win_ptr)
        return (free(data.mlx_ptr), 1);
    // Cargar imágenes XPM
    put_images(&data);
    // Dibujar el mapa con imágenes
    draw_map(&data);
    // Manejo de eventos
    mlx_key_hook(data.win_ptr, handle_keypress, &data);
    mlx_loop(data.mlx_ptr);
    // Liberar memoria del mapa al salir
    free_map(&data.map);
    return (0);
}*/
/*
    printf("Mapa leído correctamente:\n");
    for (int i = 0; i < data.map.height; i++)
        printf("%s\n", data.map.grid[i]);

    printf("Tamaño del mapa: %d x %d\n", data.map.width, data.map.height);
    printf("Tamaño de la ventana: %d x %d\n", data.win_width, data.win_high);

*/
