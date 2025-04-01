/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:03:31 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/20 15:25:17 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unistd.h"
# include "fcntl.h"
# include "stdlib.h"
# include "stdio.h"

// #ifndef BUFFER_SIZE
// #define BUFFER_SIZE 42
// #endif

char *get_next_line(int fd)
{
    char *buffer;
    char *line;
    int i = 0;
    int bytes_read_line;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (!buffer)
    {
        free(buffer);
        return (NULL);
    }
    line = NULL;
    while((bytes_read_line = read(fd, &buffer[i], 1)) > 0)
    {
        if (buffer[i++] == '\n')
            break;
        if(i >= BUFFER_SIZE)
            break;
    }
    if (i == 0 && bytes_read_line <= 0)
    {
        free(buffer);
        return (NULL);
    }
    buffer[i] = '\0';
    line = (char *)malloc(i + 1);
    if (!line)
        return (NULL);
    i = 0;
    while (buffer[i])
    {
        line[i] = buffer[i];
        i++;
    }
    line[i] = '\0';
    free (buffer);
    return (line);
}

// int main(void)
// {
//     int fd = open("text.txt", O_RDONLY);
//     char *line;
    
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }
//     close(fd);
//     return (0);
    
// }