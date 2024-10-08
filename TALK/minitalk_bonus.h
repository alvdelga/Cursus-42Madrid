/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:36:04 by alvdelga          #+#    #+#             */
/*   Updated: 2024/10/05 09:11:19 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <signal.h>

# define ERROR_1 "[!] Failed to send signal\n"
# define ERROR_2 "[!] Invalid arguments\n"
# define ERROR_3 "[!] Incorrect PID\n"
# define ERROR_4 "[!] Failed to communicate with server\n"
# define ERROR_5 "[!] String is empty\n"
# define ERROR_6 "[!] Server is busy. Please retry later\n"
# define ERROR_7 "[!] Failed to communicate with client\n"


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

void	send_signal_client(int pid, int signal);
void	start_server(void);
void	manage_errors_s(char *error);
void	reset_server(char *error);

#endif