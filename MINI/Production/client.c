/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leam <leam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 09:55:46 by leam              #+#    #+#             */
/*   Updated: 2024/09/28 10:10:20 by leam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "stdlib.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // Para atoi()
#include <stddef.h>  // Para size_t

void send_char(pid_t server_pid, char c) {
    for (int i = 7; i >= 0; i--) {
        if ((c >> i) & 1) {
            kill(server_pid, SIGUSR2); // Enviamos un '1' usando SIGUSR2
        } else {
            kill(server_pid, SIGUSR1); // Enviamos un '0' usando SIGUSR1
        }
        usleep(100); // Pequeña pausa para asegurar que el servidor reciba la señal
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Uso: %s <PID del servidor> <mensaje>\n", argv[0]);
        return 1;
    }

    pid_t server_pid = atoi(argv[1]);
    char *mensaje = argv[2];

    for (size_t i = 0; i < strlen(mensaje); i++) {
        send_char(server_pid, mensaje[i]); // Enviamos cada caracter
    }

    return 0;
}
