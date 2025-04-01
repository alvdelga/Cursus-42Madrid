/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:12:20 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/11 09:12:20 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct  s_point
{
    int           x;
    int           y;
}               t_point;

void fill(char **tab, t_point size, t_point begin, char to_fill)
{
    if(begin.y < 0 || begin.y >= size.y || begin.x < 0 || begin.x >= size.y || tab[begin.y][begin.x] != to_fill)
        return;
    tab[begin.y][begin.x] == 'F';
    fill(tab, size, (t_point){begin.x -1, begin.y}, to_fill);
    fill(tab, size, (t_point){begin.x + 1, begin.y}, to_fill);
    fill(tab, size, (t_point){begin.x, begin.y -1}, to_fill);
    fill(tab, size, (t_point){begin.x, begin.y + 1}, to_fill);

}


void  flood_fill(char **tab, t_point size, t_point begin)
{
    fill(tab, size, begin, tab[begin.y][begin.x]);
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}









































// void	fill(char **tab, t_point size, t_point begin, char to_fill)
// {
// 	if (begin.y < 0 || begin.y >= size.y || begin.x < 0 || begin.x >= size.x || tab[begin.y][begin.x] != to_fill)
// 		return;

// 	tab[begin.y][begin.x] = 'F';
// 	fill(tab, size, (t_point){begin.x - 1, begin.y}, to_fill);
// 	fill(tab, size, (t_point){begin.x + 1, begin.y}, to_fill);
// 	fill(tab, size, (t_point){begin.x, begin.y - 1}, to_fill);
// 	fill(tab, size, (t_point){begin.x, begin.y + 1}, to_fill);
// }

// void	flood_fill(char **tab, t_point size, t_point begin)
// {
// 	fill(tab, size, begin, tab[begin.y][begin.x]);
// }