/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:17:34 by apaterno          #+#    #+#             */
/*   Updated: 2024/07/04 14:17:40 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minitalk.h"

t_server	g_server;

void	init_server(void)
{
	g_server.bit = 0;
	g_server.chr = 0;
	g_server.transmiting = 0;
	g_server.pid_client = 0;
}

void	print_bits(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		g_server.chr |= (0x01 << g_server.bit);
	g_server.bit++;
	if (g_server.bit == 8)
	{
		if (g_server.chr == '\0')
		{
			ft_printf("\nClient message %d received\n", g_server.pid_client);
			send_signal_c(g_server.pid_client, SIGUSR2);
			init_server();
		}
		ft_printf("%c", g_server.chr);
		g_server.bit = 0;
		g_server.chr = 0;
	}
	usleep(100);
	kill(info->si_pid, SIGUSR1);
}

void	client_conections(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (g_server.pid_client == 0)
	{
		g_server.pid_client = info->si_pid;
		g_server.transmiting = 1;
	}
	else if (g_server.pid_client != info->si_pid && g_server.transmiting)
		send_signal_c(info->si_pid, SIGUSR2);
	if (g_server.pid_client == info->si_pid && g_server.transmiting)
		print_bits(sig, info, context);
}

void	server_loop(void)
{
	while (1)
	{
		if (g_server.pid_client != 0)
			send_signal_c(g_server.pid_client, 0);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;
	int					check;

	(void)argv;
	pid = getpid();
	sa.sa_sigaction = &client_conections;
	if (argc != 1)
		manage_errors_s(ERROR_2);
	if ((sigemptyset(&sa.sa_mask) != 0))
		manage_errors_s(ERROR_1);
	sa.sa_flags = SA_SIGINFO;
	if ((sigaction(SIGUSR1, &sa, NULL) != 0))
		manage_errors_s(ERROR_1);
	if ((sigaction(SIGUSR2, &sa, NULL) != 0))
		manage_errors_s(ERROR_1);
	ft_printf("pid: %d\n", pid);
	init_server();
	server_loop();
	return (0);
}
