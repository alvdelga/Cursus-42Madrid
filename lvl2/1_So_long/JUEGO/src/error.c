/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:00:00 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/03 19:59:14 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdlib.h>

// void error_cases(const char *msg, t_data *data)
// {
//     ft_printf("Error: %s\n", msg);

//     // Liberar imágenes
//     if (data->mlx_ptr)
//     {
//         free_images(data);
//         if (data->win_ptr)
//             mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        
//         // Cerrar X11 antes de destruir el display
//         mlx_destroy_display(data->mlx_ptr);
//         free(data->mlx_ptr);
//     }

//     // Liberar el mapa
//     free_map(&data->map);

//     exit(EXIT_FAILURE);
// }
void error_cases(const char *msg, t_data *data)
{
    // Imprimir el mensaje de error
    ft_printf("Error: %s\n", msg);

    // Liberar recursos si 'data' no es NULL
    if (data)
    {
        // Liberar imágenes (si están asignadas)
        if (data->mlx_ptr)
        {
            free_images(data);
            if (data->win_ptr)
                mlx_destroy_window(data->mlx_ptr, data->win_ptr);

            mlx_destroy_display(data->mlx_ptr);
            free(data->mlx_ptr);
        }

        // Liberar el mapa
        if (data->map.grid)
            free_map(&data->map);
    }

    // Finalizar el programa con un código de error
    exit(EXIT_FAILURE);
}

