#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

volatile sig_atomic_t g_signal_received = 0;

void handle_signal(int sig)
{
    if (sig == SIGUSR1) {
        g_signal_received = 1; // Confirmación recibida
    }
}

void send_char(pid_t server_pid, char c)
{
    for (int i = 0; i < 8; i++) {
        g_signal_received = 0; // Resetear antes de cada envío de bit
        
        if ((c >> i) & 1)
            kill(server_pid, SIGUSR1); // Enviar bit 1
        else
            kill(server_pid, SIGUSR2); // Enviar bit 0
        
        while (!g_signal_received) // Esperar confirmación del servidor
            pause(); // Pausar hasta recibir la señal
    }
}

void send_string(pid_t server_pid, const char *str)
{
    while (*str) {
        send_char(server_pid, *str);
        str++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <PID_servidor> <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid_t server_pid = atoi(argv[1]);

    if (server_pid <= 0) {
        fprintf(stderr, "PID del servidor inválido\n");
        exit(EXIT_FAILURE);
    }

    // Configurar el manejador de la señal SIGUSR1
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("Error en sigaction");
        exit(EXIT_FAILURE);
    }

    send_string(server_pid, argv[2]);

    return 0;
}

