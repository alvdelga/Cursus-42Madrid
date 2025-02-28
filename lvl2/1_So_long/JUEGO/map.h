/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:23:41 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/28 12:48:12 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <fcntl.h>  // open()
# include <unistd.h> // read(), close()
# include <stdlib.h> // malloc(), free()
# include <stdio.h>  // perror()
#include <string.h>

typedef struct s_map {
    char    **grid;   // Matriz para almacenar el mapa
    int     width;    // Ancho del mapa
    int     height;   // Alto del mapa
}   t_map;

int  load_map(const char *filename, t_map *map);
void free_map(t_map *map);

#endif
