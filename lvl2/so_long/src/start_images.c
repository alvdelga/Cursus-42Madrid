/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:22:47 by miguelgo          #+#    #+#             */
/*   Updated: 2024/05/05 20:59:03 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images(t_atrib *atribs)
{
	int	len;

	len = 70;
	atribs->wall = mlx_xpm_file_to_image(atribs->mlx, WALL, &len, &len);
	atribs->player = mlx_xpm_file_to_image(atribs->mlx, BART, &len, &len);
	atribs->floor = mlx_xpm_file_to_image(atribs->mlx, FLOOR, &len, &len);
	atribs->exit = mlx_xpm_file_to_image(atribs->mlx, EXIT, &len, &len);
	atribs->objects = mlx_xpm_file_to_image(atribs->mlx, OBJECT, &len, &len);
}

void	render(t_map ***final_map, t_atrib *atribs)
{
	int	i;
	int	j;

	j = 0;
	while (final_map[j])
	{
		i = 0;
		while (final_map[j][i] && final_map[j][i]->content != '\n')
		{
			put_visual(i, j, final_map[j][i]->content, atribs);
			i++;
		}
		j++;
	}
}

void	put_visual(int i, int j, char c, t_atrib *atribs)
{
	if (c != '\n')
		mlx_put_image_to_window(atribs->mlx, atribs->win,
			atribs->floor, i * 70, j * 70);
	if (c == '1')
		mlx_put_image_to_window(atribs->mlx, atribs->win,
			atribs->wall, i * 70, j * 70);
	if (c == 'P')
		mlx_put_image_to_window(atribs->mlx, atribs->win,
			atribs->player, i * 75, j * 70);
	if (c == 'E' && atribs->escape == 1)
		mlx_put_image_to_window(atribs->mlx, atribs->win,
			atribs->exit, i * 70, j * 70);
	if (c == 'C')
		mlx_put_image_to_window(atribs->mlx, atribs->win,
			atribs->objects, i * 80, j * 88);
	if (c == 'F')
	{
		mlx_put_image_to_window(atribs->mlx, atribs->win,
			atribs->exit, i * 70, j * 70);
		mlx_put_image_to_window(atribs->mlx, atribs->win,
			atribs->player, i * 75, j * 70);
	}
}
