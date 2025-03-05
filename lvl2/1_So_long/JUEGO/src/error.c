/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:00:00 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/05 14:14:22 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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

int	has_valid_extension(const char *filename, const char *ext)
{
	const char	*dot;
	size_t		filename_len;
	size_t		ext_len;

	filename_len = ft_strlen (filename);
	ext_len = ft_strlen (ext);
	if (filename_len <= ext_len)
		return (0);
	dot = filename + filename_len - ext_len;
	if (strcmp(dot, ext) != 0)
		return (0);
	if (dot == filename || *(dot - 1) == '.')
		return (0);
	return (1);
}
