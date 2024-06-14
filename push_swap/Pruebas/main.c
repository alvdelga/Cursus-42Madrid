// main.c
#include <stdio.h>
#include "stack.h"

void printStack(Stack* stack, char name) {
    printf("%c: ", name);
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack a, b;
    initStack(&a);
    initStack(&b);

    // Añadir elementos aleatorios al stack a
    push(&a, 8);
    push(&a, 5);
    push(&a, 6);
    push(&a, 3);
    push(&a, 1);
    push(&a, 2);

    printf("Inicialización:\n");
    printStack(&a, 'a');
    printStack(&b, 'b');

    // Ejecutar operaciones para ordenar el stack a
    sa(&a);
    pb(&a, &b);
    pb(&a, &b);
    pb(&a, &b);
    rr(&a, &b);
    rrr(&a, &b);
    sa(&a);
    pa(&a, &b);
    pa(&a, &b);
    pa(&a, &b);

    printf("Después de ordenar:\n");
    printStack(&a, 'a');
    printStack(&b, 'b');

    return 0;
}

