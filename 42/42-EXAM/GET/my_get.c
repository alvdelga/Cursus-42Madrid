/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:54:00 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/20 11:05:58 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
    char *buffer;
    char *line;
    int bytes_read;
    int i = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = (char *)malloc(BUFFER_SIZE + 1);
    line = NULL;
    if (!buffer)
        return (NULL);
    while ((bytes_read = read(fd, &buffer[i], 1)) > 0)
    {
        if (buffer[i++] == '\n')
            break;
        if (i >= BUFFER_SIZE)
            break;
    }
    if (bytes_read <= 0 && i == 0)
    {
        free(buffer);
        return (NULL);
    }
    buffer[i] == '\0';
    line = (char *)malloc(i + 1);
    if (!line)
    {
        free(buffer);
        return(NULL);
    }
    i = 0;
    while (buffer[i])
    {
        line[i] = buffer[i];
        i++;
    }
    line = '\0';
    return (line);
}