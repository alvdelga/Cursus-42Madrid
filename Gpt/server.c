#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

volatile sig_atomic_t g_received_char = 0;

void handle_signal(int sig, siginfo_t *info, void *context)
{
    static int bit_index = 0;
    static char current_char = 0;
    
    (void)context; // Para evitar warnings por el uso no de la variable

    if (sig == SIGUSR1)
        current_char |= (1 << bit_index); // Suma el bit
    bit_index++;

    if (bit_index == 8) { // Si ha completado un char (8 bits)
        write(1, &current_char, 1); // Imprimir el char
        current_char = 0;
        bit_index = 0;
    }

    // Enviar señal de confirmación al cliente
    kill(info->si_pid, SIGUSR1);
}

void setup_signal_handlers(void)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handle_signal;
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGUSR1);
    sigaddset(&sa.sa_mask, SIGUSR2);
    
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1) {
        perror("Error en sigaction");
        exit(EXIT_FAILURE);
    }
}

int main(void)
{
    pid_t pid = getpid();
    printf("PID del servidor: %d\n", pid);

    setup_signal_handlers();

    // El servidor se queda en pausa esperando señales
    while (1) {
        pause(); // Espera a recibir una señal
    }

    return 0;
}

