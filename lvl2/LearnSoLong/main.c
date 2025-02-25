/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:35:04 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/25 15:31:01 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 600

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp, line_length, endian;
	int		x, y;

	// Inicializa MiniLibX
	mlx = mlx_init();
	if (!mlx)
	{
		printf("Error: No se pudo inicializar MiniLibX\n");
		return (1);
	}

	// Crea una ventana de 1920x1080
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "MiniLibX Window");
	if (!mlx_win)
	{
		printf("Error: No se pudo crear la ventana\n");
		return (1);
	}

	// Crea una imagen
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	addr = mlx_get_data_addr(img, &bpp, &line_length, &endian);

	// Dibuja un pequeño cuadrado rojo (100x100) sin usar 'for'
	y = 100;
	while (y < 150)
	{
		x = 100;
		while (x < 150)
		{
			*(unsigned int *)(addr + (y * line_length + x * (bpp / 8))) = 0x00FF0000; // Color rojo
			x++;
		}
		y++;
	}

	// Muestra la imagen en la ventana
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);

	// Mantiene la ventana abierta
	mlx_loop(mlx);
	return (0);
}
