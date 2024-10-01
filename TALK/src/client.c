/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:37:42 by alvdelga          #+#    #+#             */
/*   Updated: 2024/10/01 12:37:42 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	g_checker;

void	recive_signal(int sig, siginfo_t *info, void *context)
{
	static int	connected;

	(void)info;
	(void)context;
	if (sig == SIGUSR1)
	{
		g_checker = 1;
		connected = 1;
	}
	else if (sig == SIGUSR2 && connected)
	{
		ft_printf("[+] Message delivered. Connection finished.\n");
		exit(EXIT_SUCCESS);
	}
	else if (sig == SIGUSR2 && !connected)
	{
		manage_errors_c(ERROR_6);
		exit(EXIT_FAILURE);
	}
}

void	send_to_server(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_checker = 0;
		if (c & (0x01 << bit))
			send_signal_s(pid, SIGUSR1);
		else
			send_signal_s(pid, SIGUSR2);
		bit++;
		while (g_checker != 1)
		{
			usleep(100);
			send_signal_s(pid, 0);
		}
	}
}

static void	client_loop(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_to_server(pid, str[i]);
		i++;
	}
	send_to_server(pid, '\0');
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	sa.sa_sigaction = &recive_signal;
	sa.sa_flags = SA_SIGINFO;
	if (sigemptyset(&sa.sa_mask) == -1)
		manage_errors_c(ERROR_1);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		manage_errors_c(ERROR_1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		manage_errors_c(ERROR_1);
	if (argc == 3)
	{
		check_arg(argv[1], argv[2]);
		client_loop(ft_atoi(argv[1]), argv[2]);
	}
	else
		manage_errors_c(ERROR_2);
	return (0);
}
