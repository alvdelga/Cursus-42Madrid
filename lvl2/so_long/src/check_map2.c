/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:28:48 by miguelgo          #+#    #+#             */
/*   Updated: 2024/05/05 21:03:07 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_valid(char **all_map, t_atrib *atribs)
{
	int		i;
	int		j;

	atribs->exit_found = 0;
	atribs->coins_found = 0;
	i = go_to_init(all_map, 'i');
	j = go_to_init(all_map, 'j');
	if (!ft_floodfill_coins(j, i, all_map, atribs))
		error_cases("The map don't have solution");
}

int	ft_floodfill_coins(int x, int y, char **all_map, t_atrib *atribs)
{
	if (x < 0 || y < 0 || !all_map[x] || !all_map[x][y])
		return (0);
	if (all_map[x][y] == '1' || all_map[x][y] == 'v')
		return (0);
	if (all_map[x][y] == 'C')
		atribs->coins_found++;
	if (all_map[x][y] == 'E')
		atribs->exit_found = 1;
	if (atribs->coins_found == atribs->coins && atribs->exit_found)
		return (1);
	all_map[x][y] = 'v';
	if (ft_floodfill_coins(x + 1, y, all_map, atribs))
		return (1);
	if (ft_floodfill_coins(x - 1, y, all_map, atribs))
		return (1);
	if (ft_floodfill_coins(x, y + 1, all_map, atribs))
		return (1);
	if (ft_floodfill_coins(x, y - 1, all_map, atribs))
		return (1);
	return (0);
}

int	go_to_init(char **all_map, char c)
{
	int	j;
	int	i;

	j = 0;
	while (all_map[j])
	{
		i = 0;
		while (all_map[j][i])
		{
			if (all_map[j][i] == 'P')
			{
				if (c == 'j')
					return (j);
				else if (c == 'i')
					return (i);
			}
			i++;
		}
		j++;
	}
	return (0);
}
