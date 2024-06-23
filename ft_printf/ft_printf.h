/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:08:43 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/09 14:17:16 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>

int				ft_putnbr_base(unsigned int nbr, char *base);
int				ft_putstr_fd(char *s, int fd);
int				ft_putchar_fd(char c, int fd);
int				ft_putnbr_fd(int n, int fd, int i);
int				ft_printf(const char *format, ...);
int				ft_putunsigned(unsigned int n, int i);
int				ft_memdir(void *p);
size_t			ft_strlen(const char *str);
#endif
