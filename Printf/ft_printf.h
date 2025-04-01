/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanmetol <sanmetol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:39:59 by sanmetol          #+#    #+#             */
/*   Updated: 2023/10/18 19:53:11 by sanmetol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_va_arg(char s, va_list args_l, int *count);
int		ft_printf(char const *s, ...);
void	ptrhexa(unsigned long int n, int *count);
void	ft_puthexa(unsigned int n, char x_or_X, int *count);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putnbr(int n, int *count);
char	*ft_itoa_u(unsigned int n);

#endif