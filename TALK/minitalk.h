/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leam <leam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:06:19 by leam              #+#    #+#             */
/*   Updated: 2024/10/01 00:06:19 by leam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <signal.h>

# define ERROR_1 "Signal error\n"
# define ERROR_2 "Arguments errors\n"
# define ERROR_3 "PID error\n"
# define ERROR_4 "Connection error\n"
# define ERROR_5 "Empty string\n"
# define ERROR_6 "Server busy. Try later\n"
# define ERROR_7 "\nConnection error\n"

typedef struct s_server
{
	int				pid_client;
	unsigned char	chr;
	int				bit;
	int				transmiting;
}	t_server;

void	manage_errors_c(char *error);
void	send_signal_s(int pid, int signal);
void	check_arg(char *arg_1, char *arg_2);
//server
void	send_signal_c(int pid, int signal);
void	init_server(void);
void	manage_errors_s(char *error);
void	reset_server(char *error);

#endif
