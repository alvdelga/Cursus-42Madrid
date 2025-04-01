/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:52:15 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/05 15:15:45 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// Asignar memoria para la matriz del mapa
int	allocate_map_memory(t_map *map)
{
	int	i;

	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
	{
		perror("Error al asignar memoria");
		return (0);
	}
	i = 0;
	while (i < map->height)
	{
		map->grid[i] = NULL;
		i++;
	}
	map->grid[map->height] = NULL;
	return (1);
}

// Liberar memoria del mapa
void	free_map(t_map *map)
{
	int	i;

	if (!map || !map->grid)
		return ;
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i])
			free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

void	free_images(t_data *data)
{
	if (data->mlx_ptr)
	{
		if (data->wall)
			mlx_destroy_image(data->mlx_ptr, data->wall);
		if (data->player)
			mlx_destroy_image(data->mlx_ptr, data->player);
		if (data->floor)
			mlx_destroy_image(data->mlx_ptr, data->floor);
		if (data->exit)
			mlx_destroy_image(data->mlx_ptr, data->exit);
		if (data->objects)
			mlx_destroy_image(data->mlx_ptr, data->objects);
	}
}

void	remove_newline(char *line, int *len)
{
	if (line[*len - 1] == '\n')
	{
		line[*len - 1] = '\0';
		(*len)--;
	}
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	lens1;

	lens1 = ft_strlen(s1);
	s2 = malloc((lens1 + 1));
	if (!s2)
		return (NULL);
	while (*s1)
	{
		*s2++ = *s1++;
	}
	*s2 = '\0';
	return (s2 - lens1);
}
// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }
