#include <stdarg.h>
#include <stdio.h>

// Función que toma múltiples argumentos fijos y variables
void example_function(int a, double b, char *c, ...) {
    va_list args;
    va_start(args, c);  // Inicializa args después del último argumento fijo

    // Supongamos que los argumentos variables son enteros
    while (1) {
        int num = va_arg(args, int);
        if (num == -1) break;  // Usamos -1 como terminador
        printf("%d\n", num);
    }

    va_end(args);  // Limpia args
}

int main() {
    // Llamada a la función con argumentos fijos y variables
    example_function(1, 2.5, "example", 10, 20, 30, -1);
    example_function(2, 3.14, "another example", 5, 15, 25, 35, -1);

    return 0;
}
