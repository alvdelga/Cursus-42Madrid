/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:22:24 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/28 12:52:32 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "ft_printf/ft_printf.h"

int handle_keypress(int keysym, t_data *data)
{
    if (keysym == 65307) // Tecla ESC para salir
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(0);
    }
    ft_printf("Key press: %d\n", keysym);
    return (0);
}

int main(int argc, char **argv)
{
    t_data  data;
    
    if (argc != 2)
        return (ft_printf("Uso: %s <archivo.ber>\n", argv[0]), 1);
    
    // Cargar el mapa desde el archivo .ber
    if (!load_map(argv[1], &data.map))
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
