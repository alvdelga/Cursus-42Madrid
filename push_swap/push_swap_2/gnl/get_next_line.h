/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:38:56 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/18 20:03:07 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 482
# endif

# include <unistd.h>
# include <stdlib.h>

char			*get_next_line(int fd);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strchr(char *s, int c);
unsigned long	ft_strlenn(char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*res_file(char *res);
char			*read_file(int fd, char *res);
char			*make_line(char *res);

#endif
