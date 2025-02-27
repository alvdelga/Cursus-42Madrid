#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_data {
    void    *mlx_ptr;
    void    *win_ptr;
	void    *img;
    int     img_width;
    int     img_height;
}   t_data;

int handle_keypress(int keysym, t_data *data)
{
    if (keysym == 65307) // Código de tecla para ESC
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(0);
    }
    printf("Tecla presionada: %d\n", keysym);
    return (0);
}

int main(void)
{
    t_data  data;
	int ventana_ancho = 800;
    int ventana_alto = 600;
    int offset_x, offset_y;

    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "Mi Juego");
    if (data.win_ptr == NULL)
    {
        free(data.mlx_ptr);
        return (1);
    }

	// Cargar la imagen de fondo
    data.img = mlx_xpm_file_to_image(data.mlx_ptr, "fondo.xpm", &data.img_width, &data.img_height); // Cargar la imagen de fondo
    if (!data.img)
    {
        printf("Error: No se pudo cargar la imagen de fondo\n");
        return (1);
    }

	    // Calcular el desplazamiento para centrar la imagen
		offset_x = (data.img_width - ventana_ancho) / 2;
		offset_y = (data.img_height - ventana_alto) / 2;
	
		// Asegurarse de que los offsets no sean negativos (para evitar desbordamientos)
		if (offset_x < 0) offset_x = 0;
		if (offset_y < 0) offset_y = 0;

    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, -offset_x, -offset_y); // Dibujar la imagen en la ventana
    mlx_key_hook(data.win_ptr, handle_keypress, &data);
    mlx_loop(data.mlx_ptr);
    return (0);
}
