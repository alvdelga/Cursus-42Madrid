/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:26:16 by alvdelga          #+#    #+#             */
/*   Updated: 2024/09/25 18:26:16 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <signal.h>
#include <zconf.h>
#include "minitalk.h"
#include "libft.h"

void		print_pid(void)
{
	char	*tmp_pid;

	tmp_pid = ft_itoa(getpid());
	write(1, "[+] Your Pid is: ", 17);
	write(1, tmp_pid, ft_strlen(tmp_pid));
	write(1, "\n", 1);
	free(tmp_pid);
}

void		activebit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	(void)info;
	if (!g_to_print.top_bit)
	{
		g_to_print.top_bit = 1 << 6;
		++(g_to_print.top_byte);
	}
	g_to_print.message[g_to_print.top_byte] += g_to_print.top_bit;
	g_to_print.top_bit >>= 1;
	if (g_to_print.top_byte == BUFFSIZE - 2 && !g_to_print.top_bit)
		g_to_print.buff_overflow = TRUE;
}

void		nullbit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (!g_to_print.top_bit)
	{
		g_to_print.top_bit = 1 << 6;
		++(g_to_print.top_byte);
	}
	g_to_print.top_bit >>= 1;
	if (g_to_print.top_byte == BUFFSIZE - 2 && !g_to_print.top_bit)
		g_to_print.buff_overflow = TRUE;
	else if (!g_to_print.message[g_to_print.top_byte]
		&& !g_to_print.top_bit)
	{
		g_to_print.all_receive = TRUE;
		kill(info->si_pid, SIGUSR1);
	}
}

_Bool		main_handler(void)
{
	while (1)
	{
		pause();
		if (g_to_print.all_receive || g_to_print.buff_overflow)
		{
			write(1, g_to_print.message, ft_strlen(g_to_print.message));
			ft_bzero(g_to_print.message, BUFFSIZE);
			g_to_print.top_byte = 0;
			g_to_print.top_bit = 1 << 6;
			if (g_to_print.all_receive)
				write(1, "\n", 1);
			g_to_print.all_receive = FALSE;
			g_to_print.buff_overflow = FALSE;
		}
	}
	//return (TRUE);
}

int			main(void)
{
	struct sigaction active_act;
	struct sigaction null_act;

	active_act.sa_sigaction = activebit;
	null_act.sa_sigaction = nullbit;
	active_act.sa_flags = SA_SIGINFO;
	null_act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &active_act, NULL) != 0)
		error("[!] Signal error\n");
	if (sigaction(SIGUSR2, &null_act, NULL) != 0)
		error("[!] Signal error\n");
	print_pid();
	ft_bzero(g_to_print.message, BUFFSIZE);
	main_handler();
}

// struct sigaction {
//     void (*sa_handler)(int);
//     void (*sa_sigaction)(int, siginfo_t *, void *);
//     sigset_t sa_mask;
//     int sa_flags;
//     void (*sa_restorer)(void);
// };

// int main(void)
// {
//     struct sigaction active_act;
//     struct sigaction null_act;

//     // Inicializa g_to_print aquí
//     g_to_print.top_byte = 0;
//     g_to_print.top_bit = 0;
//     g_to_print.buff_overflow = FALSE;
//     g_to_print.all_receive = FALSE;
//     ft_bzero(g_to_print.message, BUFFSIZE);

//     active_act.sa_sigaction = activebit;
//     null_act.sa_sigaction = nullbit;
//     active_act.sa_flags = SA_SIGINFO;
//     null_act.sa_flags = SA_SIGINFO;

// 	// Inicializa las estructuras sigaction
//     sigemptyset(&active_act.sa_mask);
//     sigemptyset(&null_act.sa_mask);

//     if (sigaction(SIGUSR1, &active_act, NULL) != 0)
//         error("[!] Signal error\n");
//     if (sigaction(SIGUSR2, &null_act, NULL) != 0)
//         error("[!] Signal error\n");

//     print_pid();
//     main_handler();
// }