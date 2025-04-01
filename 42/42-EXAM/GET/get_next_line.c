#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	int		bytes_read;
	int		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	line = NULL;
	if (!buffer)
		return (NULL);
	i = 0;
	while ((bytes_read = read(fd, &bu ffer[i], 1)) > 0)
	{
		if (buffer[i++] == '\n')
        {
			break;
        }
		if (i >= BUFFER_SIZE)
			break;
	}
	if (bytes_read <= 0 && i == 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	line = (char *)malloc(i + 1);
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	free(buffer);
	return (line);
}

int main(void)
{
    int fd;
    char *line;

    // Abrir el archivo para leer
    fd = open("test.txt", O_RDONLY); // Asegúrate de tener un archivo "test.txt" en el mismo directorio
    if (fd == -1) {
        perror("Error abriendo el archivo");
        return (1);
    }

    // Leer el archivo línea por línea
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);  // Imprimir la línea leída
        free(line);          // Liberar la memoria asignada para la línea
    }

    // Cerrar el archivo después de la lectura
    close(fd);

    return 0;
}