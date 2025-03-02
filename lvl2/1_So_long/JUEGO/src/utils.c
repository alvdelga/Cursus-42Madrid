/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:52:15 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/02 13:11:44 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// Asignar memoria para la matriz del mapa
int	allocate_map_memory(t_map *map)
{
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (perror("Error al asignar memoria"), 0);
	return (1);
}

// Liberar memoria del mapa
void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->grid[i])
		free(map->grid[i++]);
	free(map->grid);
}

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }
