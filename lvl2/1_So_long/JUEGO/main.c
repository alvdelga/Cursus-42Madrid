/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:22:24 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/28 14:10:02 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "ft_printf/ft_printf.h"

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
        // Si hay un coleccionable, reducir el contador
        if (data->map.grid[new_y][new_x] == 'C')
            data->collectibles--;

        // Mover al jugador
        data->map.grid[data->player_y][data->player_x] = '0'; // Vaciar la posición anterior
        data->map.grid[new_y][new_x] = 'P'; // Colocar al jugador en la nueva posición
        data->player_x = new_x;
        data->player_y = new_y;
        data->moves++;

        // Mostrar movimientos en consola
        ft_printf("Movimientos: %d\n", data->moves);

        // Redibujar el mapa
        draw_map(data);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
    }

    return (0);
}


int main(int argc, char **argv)
{
    t_data  data;
    
    if (argc != 2)
        return (ft_printf("Uso: %s <archivo.ber>\n", argv[0]), 1);
    
    // Cargar el mapa desde el archivo .ber
	if (!load_map(argv[1], &data.map, &data)) // Pasamos &data para capturar player_x y player_y
    return (ft_printf("Error al cargar el mapa\n"), 1);

    // Configurar ventana según el tamaño del mapa
    data.win_width = data.map.width * 50; // Cada celda es de 50px
    data.win_high = data.map.height * 50;

	printf("Mapa leído correctamente:\n");
	for (int i = 0; i < data.map.height; i++)
    printf("%s\n", data.map.grid[i]);

	printf("Tamaño del mapa: %d x %d\n", data.map.width, data.map.height);
	printf("Tamaño de la ventana: %d x %d\n", data.win_width, data.win_high);


    // Inicializar MiniLibX
    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (1);

    // Crear una ventana
    data.win_ptr = mlx_new_window(data.mlx_ptr, data.win_width, data.win_high, "Mi Juego");
    if (!data.win_ptr)
        return (free(data.mlx_ptr), 1);

    // Crear una imagen en memoria
    data.img = mlx_new_image(data.mlx_ptr, data.win_width, data.win_high);
    if (!data.img)
        return (ft_printf("Error: No se pudo crear la imagen\n"), 1);

    // Obtener la dirección de la imagen para modificarla
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

    // Dibujar el mapa en la ventana
    draw_map(&data);

    // Mostrar la imagen en la ventana
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 0);

    // Manejo de eventos
    mlx_key_hook(data.win_ptr, handle_keypress, &data);
    mlx_loop(data.mlx_ptr);

    // Liberar memoria del mapa al salir
    free_map(&data.map);
    return (0);
}
