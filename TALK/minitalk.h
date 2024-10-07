/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:36:38 by alvdelga          #+#    #+#             */
/*   Updated: 2024/10/01 12:36:38 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <signal.h>

# define RED "\033[0;31m"
# define RESET "\033[0m"

# define ERROR_1 RED "[!]" RESET " Failed to send signal\n"
# define ERROR_2 RED "[!]" RESET " Invalid arguments\n"
# define ERROR_3 RED "[!]" RESET " Incorrect PID\n"
# define ERROR_4 RED "[!]" RESET " Failed to communicate with server\n"
# define ERROR_5 RED "[!]" RESET " String is empty\n"
# define ERROR_6 RED "[!]" RESET " Server is busy. Please retry later\n"
# define ERROR_7 RED "[!]" RESET " Failed to communicate with client\n"
# define ERROR_8 RED "[!]" RESET " Uso: ./client <PID of server> <Message>\n"

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