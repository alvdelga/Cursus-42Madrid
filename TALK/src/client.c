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

int	g_signal_received;

void	recive_signal(int sig, siginfo_t *info, void *context)
{
	static int	connected;

	(void)info;
	(void)context;
	int pid;
	pid = getpid();
	if (sig == SIGUSR1)
	{
		g_signal_received = 1;
		connected = 1;
	}
	else if (sig == SIGUSR2 && connected)
	{
		ft_printf("[+] Done! Message sent.\n");
		ft_printf("[+] My Pid => %d\n", pid);
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
		g_signal_received = 0;
		if (c & (0x01 << bit))
			send_signal_s(pid, SIGUSR1);
		else
			send_signal_s(pid, SIGUSR2);
		bit++;
		while (g_signal_received != 1)
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

void	ignore_sigint(int sig)
{
	(void)sig;
	printf(" [!] SIGINT blocked, use Ctrl + Z\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	s_sa;

	s_sa.sa_sigaction = &recive_signal;
	s_sa.sa_flags = SA_SIGINFO;
	if (sigemptyset(&s_sa.sa_mask) != 0)
		manage_errors_c(ERROR_1);
	if (sigaction(SIGUSR1, &s_sa, NULL) != 0)
		manage_errors_c(ERROR_1);
	if (sigaction(SIGUSR2, &s_sa, NULL) != 0)
		manage_errors_c(ERROR_1);
	struct sigaction	sigint_sa;
	sigint_sa.sa_handler = &ignore_sigint;
	sigint_sa.sa_flags = 0;
	if (sigaction(SIGINT, &sigint_sa, NULL) != 0)
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
