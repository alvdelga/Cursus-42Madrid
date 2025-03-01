/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:34:32 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/18 20:02:30 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*beforejoin(char *res, char *tmp)
{
	char	*newres;

	newres = ft_strjoin(res, tmp);
	free(res);
	return (newres);
}

char	*make_line(char *res)
{
	int		i;
	char	*line;

	i = 0;
	if (res[i] == '\0')
		return (NULL);
	while (res[i] != '\0' && res[i] != '\n')
		i++;
	if (res[i] == '\0')
		i++;
	else if (res[i] == '\n')
		i = i + 2;
	line = ft_calloc(sizeof(char), (i));
	i = 0;
	while (res[i] != '\0' && res[i] != '\n')
	{
		line[i] = res[i];
		i++;
	}
	if (res[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*res_file(char *res)
{
	int		i;
	char	*new_res;
	int		c;

	i = 0;
	c = 0;
	while (res[i] != '\0' && res[i] != '\n')
		i++;
	if (res[i] == '\0')
	{
		free (res);
		return (NULL);
	}
	new_res = ft_calloc(sizeof(char), (ft_strlenn(res) - i + 1));
	i++;
	while (res[i] != '\0')
	{
		new_res[c] = res[i];
		i++;
		c++;
	}
	free (res);
	return (new_res);
}

char	*read_file(int fd, char *res)
{
	int		bytes_read;
	char	*tmp;

	if (!res)
		res = ft_calloc(sizeof(char), 1);
	tmp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(tmp);
			free(res);
			res = NULL;
			tmp = NULL;
			return (NULL);
		}
		tmp[bytes_read] = '\0';
		res = beforejoin(res, tmp);
		if (ft_strchr(res, '\n'))
			break ;
	}
	free (tmp);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	res = read_file(fd, res);
	if (res == NULL)
		return (NULL);
	line = make_line(res);
	res = res_file(res);
	return (line);
}
/*
int main()
{
    int fd = open("null_file.txt", O_RDONLY);
    char *line;
    line = get_next_line(fd);
    printf("%s", line);
    free(line); // Liberar la memoria de 'line' después de su uso
	line = get_next_line(fd);
	printf("%s", line);
	free(line); // Liberar la memoria de 'line' después de su uso
	line = get_next_line(fd);
	printf("%s", line);
	free(line); // Liberar la memoria de 'line' después de su uso
    close(fd);
    return 0;
}*/
