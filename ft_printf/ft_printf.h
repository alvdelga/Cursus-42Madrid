/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malvarde <malvarde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:08:43 by alvdelga          #+#    #+#             */
/*   Updated: 2024/06/07 11:05:16 by malvarde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
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

#endif
