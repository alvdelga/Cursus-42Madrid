#include <stdio.h>
#include <stdarg.h>

int suma(int num_args, ...) {
    int total = 0;
    va_list args;
    va_start(args, num_args);

    for (int i = 0; i < num_args; i++) {
        total += va_arg(args, int);
    }

    va_end(args);
    return total;
}

int main() {
    printf("Suma de 1, 2, 3: %d\n", suma(4, 1, 2, 3));
    printf("Suma de 4, 5, 6, 7: %d\n", suma(10, 3, 3, 4, 4, 5, 6, 7, 8, 8, 100));
    return 0;
}

