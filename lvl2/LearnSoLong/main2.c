#include <mlx.h>
#include <stdio.h>

#define WIDTH 1800
#define HEIGHT 1000

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*background;
	void	*sprite;
	int		bg_width, bg_height;
	int		sprite_width, sprite_height;

	// Inicializa MiniLibX
	mlx = mlx_init();
	if (!mlx)
	{
		printf("Error: No se pudo inicializar MiniLibX\n");
		return (1);
	}

	// Crea una ventana de 800x600
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fondo + Imagen");

	// Carga la imagen de fondo (debe ser .xpm)
	background = mlx_xpm_file_to_image(mlx, "fondo.xpm", &bg_width, &bg_height);
	if (!background)
	{
		printf("Error: No se pudo cargar la imagen de fondo\n");
		return (1);
	}

	// Carga otra imagen (sprite) para poner encima del fondo
	sprite = mlx_xpm_file_to_image(mlx, "../LONG3/sprites/item.xpm", &sprite_width, &sprite_height);
	if (!sprite)
	{
		printf("Error: No se pudo cargar la imagen superior\n");
		return (1);
	}

	// Coloca la imagen de fondo en la ventana
	mlx_put_image_to_window(mlx, mlx_win, background, 0, 0);

	// Coloca la imagen encima del fondo en una posición específica (por ejemplo, en (300,200))
	mlx_put_image_to_window(mlx, mlx_win, sprite, 300, 200);

	// Mantiene la ventana abierta
	mlx_loop(mlx);
	return (0);
}
