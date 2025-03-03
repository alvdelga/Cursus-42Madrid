/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:10:26 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/03 18:02:06 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	game_over_banner(t_data *data)
{
	ft_printf("Movimientos: %d\n", data->moves);
	ft_printf("\n\n%s", SLOW_BLINK);
	ft_printf("%s╔═╗╔═╗╔╦╗╔═╗  ╔═╗╦  ╦╔═╗╦═╗\n", RED);
	ft_printf("%s║ ╦╠═╣║║║║╣   ║ ║╚╗╔╝║╣ ╠╦╝\n", CIAN);
	ft_printf("%s╚═╝╩ ╩╩ ╩╚═╝  ╚═╝ ╚╝ ╚═╝╩╚═%s\n", BLUE, RST);
	ft_printf("%s\n", RST);

	    // ✅ Cierra correctamente X11 antes de salir
		close_x_connection(data->mlx_ptr);

		// ✅ Libera todos los recursos del juego
		free_images(data);
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free_map(&data->map);
	
		exit(0);

}
int x_close(t_data *data)
{
    if (data->mlx_ptr)
    {
        free_images(data);
        if (data->win_ptr)
            mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        
        // ✅ Cerrar X11 antes de destruir el display
        close_x_connection(data->mlx_ptr);
        mlx_destroy_display(data->mlx_ptr);
        
        free(data->mlx_ptr);
    }
    free_map(&data->map);
    exit(0);
    return (0);
}


#include <X11/Xlib.h>
void close_x_connection(void *mlx_ptr)
{
	(void)mlx_ptr;
    Display *display;

    // Obtener el Display manualmente
    display = XOpenDisplay(NULL);
    if (display)
        XCloseDisplay(display);  // ✅ Cerrar la conexión con X11
}


/*
int	x_close(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_map(&data->map);
	exit(0);
	return (0);
}
*/
