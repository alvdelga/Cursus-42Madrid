/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:37:23 by alvdelga          #+#    #+#             */
/*   Updated: 2024/10/01 12:37:23 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

t_server	g_server;

void	start_server(void)
{
	g_server.bit = 0;
	g_server.chr = 0;
	g_server.transmiting = 0;
	g_server.pid_client = 0;
}

void	print_byte(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		g_server.chr |= (0x01 << g_server.bit);
	g_server.bit++;
	if (g_server.bit == 8)
	{
		if (g_server.chr == '\0')
		{
			ft_printf("\n\n[+] Done! Message received\n");
			ft_printf("[+] Client_pid => %d\n\n", g_server.pid_client);
			send_signal_client(g_server.pid_client, SIGUSR2);
			start_server();
		}
		ft_printf("%c", g_server.chr);
		g_server.bit = 0;
		g_server.chr = 0;
	}
	usleep(100);
	kill(info->si_pid, SIGUSR1);
}

void	process_client_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (g_server.pid_client == 0)
	{
		g_server.pid_client = info->si_pid;
		g_server.transmiting = 1;
	}
	else if (g_server.pid_client != info->si_pid && g_server.transmiting)
		send_signal_client(info->si_pid, SIGUSR2);
	if (g_server.pid_client == info->si_pid && g_server.transmiting)
		print_byte(sig, info, context);
}

void	signal_wait_loop(void)
{
	while (1)
	{
		pause();
		if (g_server.pid_client != 0)
			send_signal_client(g_server.pid_client, 0);
		//usleep(50);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	s_sa;
	int					pid;
	
	(void)argv;
	pid = getpid();
	s_sa.sa_sigaction = &process_client_signal;
	s_sa.sa_flags = SA_SIGINFO;
	sigaddset(&s_sa.sa_mask, SIGINT);
	if (argc != 1)
		manage_errors_s(ERROR_2);
	if ((sigemptyset(&s_sa.sa_mask) != 0))
		manage_errors_s(ERROR_1);
	if ((sigaction(SIGUSR1, &s_sa, NULL) != 0))
		manage_errors_s(ERROR_1);
	if ((sigaction(SIGUSR2, &s_sa, NULL) != 0))
		manage_errors_s(ERROR_1);
	ft_printf("[+] Take my Pid: %d\n\n", pid);
	start_server();
	signal_wait_loop();
	return (0);
}
// struct sigaction {
//     void     (*sa_handler)(int);      // Manejador de señales o SIG_IGN, SIG_DFL
//     void     (*sa_sigaction)(int, siginfo_t *, void *); // Manejador para señales extendidas
//     sigset_t sa_mask;                 // Señales que deben bloquearse durante la ejecución del manejador
//     int      sa_flags;                // Opciones adicionales (SA_RESTART, SA_SIGINFO, etc.)
//     void     (*sa_restorer)(void);    // Esta función es obsoleta en la mayoría de los sistemas
// };

// #include <signal.h>

// int sigemptyset(sigset_t *set)
// {
//     if (set == NULL)
//     {
//         return -1;  // Error si el puntero es NULL
//     }

//     *set = 0;  // Inicializa el conjunto de señales como vacío
//     return 0;  // Éxito
// }

// #include <signal.h>

// int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)
// {
//     if (signum < 1 || signum >= NSIG || act == NULL)
//     {
//         return -1;  // Error si el número de señal es inválido o el puntero es NULL
//     }

//     // Aquí se simularía la configuración del manejador de la señal en el sistema
//     if (oldact != NULL)
//     {
//         *oldact = signal_handlers[signum];  // Guarda el manejador anterior
//     }

//     signal_handlers[signum] = *act;  // Establece el nuevo manejador para la señal

//     return 0;  // Éxito
// }
