#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

typedef struct s_data {
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img;
    char    *addr; // ✨ Nuevo: Dirección de memoria de la imagen
    int     bits_per_pixel; // ✨ Nuevo: Bits por píxel
    int     line_length; // ✨ Nuevo: Longitud de línea en memoria
    int     endian; // ✨ Nuevo: Endianess de la imagen
    int     win_width;
    int     win_high;
}   t_data;

// ✨ Nueva función: Escribir un píxel en la imagen
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    if (x >= 0 && x < data->win_width && y >= 0 && y < data->win_high)
    {
        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
    }
}

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

int main(void)
{
    t_data  data;
    data.win_width = 800;
    data.win_high = 600;
	int x;
	int y;

	y = 250;

    // Inicializar MiniLibX
    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (1);
    
    // Crear una ventana
    data.win_ptr = mlx_new_window(data.mlx_ptr, data.win_width, data.win_high, "Mi Juego");
	if (!data.win_ptr)
   		return (free(data.mlx_ptr), 1);

    // ✨ Nuevo: Crear una imagen en memoria
    data.img = mlx_new_image(data.mlx_ptr, data.win_width, data.win_high);
	if (!data.img)
    	return (ft_printf("Error: No se pudo crear la imagen\n"), 1);

    // ✨ Nuevo: Obtener la dirección de la imagen para modificarla
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

    // ✨ Nuevo: Dibujar un rectángulo rojo en la imagen usando píxeles
	while (y < 350)
	{
		x = 350;
		while (x < 450)
		{
			my_mlx_pixel_put(&data, x, y, 0xFF0000); // Rojo en formato 0xRRGGBB
			x++;
		}
		y++;
	}
    // ✨ Nuevo: Mostrar la imagen en la ventana
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 0);
    mlx_key_hook(data.win_ptr, handle_keypress, &data);
    mlx_loop(data.mlx_ptr);
    return (0);
}
