/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:37:34 by alvdelga          #+#    #+#             */
/*   Updated: 2024/10/01 12:37:34 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	send_signal_client(int pid, int signal)
{
	int	sig;

	sig = kill(pid, signal);
	if (sig != 0)
		reset_server(ERROR_7);
}

void	reset_server(char *error)
{
	ft_putstr_fd(error, 2);
	start_server();
}

void	manage_errors_s(char *error)
{
	ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}
