/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:40:24 by alvdelga          #+#    #+#             */
/*   Updated: 2024/09/30 13:59:04 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

uint8_t current_char = 0;
int bit_position = 0;

void handle_sigusr1(int sig) {
    (void)sig;
    // SIGUSR1 representa el bit 0, no necesitamos hacer nada, solo avanzamos
    bit_position++;
}

void handle_sigusr2(int sig) {
    (void)sig;
    // SIGUSR2 representa el bit 1, agregamos el bit correspondiente
    current_char |= (1 << (7 - bit_position));
    bit_position++;
}

void reset_char_if_needed() {
    if (bit_position == 8) { // Hemos recibido 8 bits, es decir, un char completo
        write(1, &current_char, 1); // Imprimir el carácter recibido
        current_char = 0; // Reiniciar el valor del carácter
        bit_position = 0; // Reiniciar la posición de bits
    }
}

int main() {
    printf("PID del servidor: %d\n", getpid());

    // Configuramos los manejadores de señal
    signal(SIGUSR1, handle_sigusr1);
    signal(SIGUSR2, handle_sigusr2);

    while (1) {
        pause(); // Esperar una señal
        reset_char_if_needed(); // Revisar si ya hemos recibido un caracter completo
    }

    return 0;
}
