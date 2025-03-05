/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:00:00 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/05 01:00:11 by alvdelga         ###   ########.fr       */
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
void	error_cases(const char *msg, t_data *data)
{
	ft_printf("Error\n: %s\n", msg);
	if (data)
	{
		if (data->mlx_ptr)
		{
			free_images(data);
			if (data->win_ptr)
				mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			mlx_destroy_display(data->mlx_ptr);
			free(data->mlx_ptr);
		}
		if (data->map.grid)
			free_map(&data->map);
	}
	exit(EXIT_FAILURE);
}
#include <string.h> // Para usar strrchr

int has_valid_extension(const char *filename, const char *ext)
{
    size_t filename_len = strlen(filename);
    size_t ext_len = strlen(ext);

    if (filename_len <= ext_len) // Si el nombre es más corto que la extensión, es inválido
        return (0);

    const char *dot = filename + filename_len - ext_len;

    // Verifica que la extensión sea correcta
    if (strcmp(dot, ext) != 0)
        return (0);

    // 🚨 Nueva validación: Asegurar que el archivo no empiece con "." ni tenga ".." antes de ".ber"
    if (dot == filename || *(dot - 1) == '.')
        return (0);

    return (1);
}
