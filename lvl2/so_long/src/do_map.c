/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:06:07 by miguelgo          #+#    #+#             */
/*   Updated: 2024/05/05 20:57:52 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	***do_map(char **map, t_map ***final_map, char *argv)
{
	int		i;
	int		j;

	j = 0;
	final_map = malloc(sizeof(t_map **) * (lines_number(argv, 'l') + 1));
	if (!final_map)
		error_cases("Ha habido un problema indesperado");
	while (map[j])
	{
		final_map[j] = malloc(sizeof(t_map *) * (lines_number(argv, 'c') + 1));
		i = 0;
		while (map[j][i])
		{
			final_map[j][i] = create_node(map[j][i]);
			i++;
		}
		j++;
	}
	final_map[j] = NULL;
	link_map(final_map, map, argv);
	return (final_map);
}

void	link_map(t_map ***final_map, char **map, char *argv)
{
	int	i;
	int	j;
	int	cols;
	int	lines;

	cols = lines_number(argv, 'c');
	lines = lines_number(argv, 'l');
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (i < cols - 1)
				final_map[j][i]->right = final_map[j][i + 1];
			if (j > 0)
				final_map[j][i]->up = final_map[j - 1][i];
			if (i > 0)
				final_map[j][i]->left = final_map[j][i - 1];
			if (j < lines - 1)
				final_map[j][i]->down = final_map[j + 1][i];
			i++;
		}
		j++;
	}
}

t_map	*create_node(char content)
{
	t_map	*move;

	move = malloc(sizeof(t_map));
	if (!move)
		error_cases("Ha habido un problema inesperado");
	move->content = content;
	move->right = NULL;
	move->up = NULL;
	move->down = NULL;
	move->left = NULL;
	return (move);
}
