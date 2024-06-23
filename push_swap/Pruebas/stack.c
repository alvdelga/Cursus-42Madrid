// stack.c
#include <stdio.h>
#include "stack.h"

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++(stack->top)] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[(stack->top)--];
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

void sa(Stack* a) {
    if (a->top > 0) {
        int temp = a->arr[a->top];
        a->arr[a->top] = a->arr[a->top - 1];
        a->arr[a->top - 1] = temp;
    }
}

void sb(Stack* b) {
    if (b->top > 0) {
        int temp = b->arr[b->top];
        b->arr[b->top] = b->arr[b->top - 1];
        b->arr[b->top - 1] = temp;
    }
}

void ss(Stack* a, Stack* b) {
    sa(a);
    sb(b);
}

void pa(Stack* a, Stack* b) {
    if (!isEmpty(b)) {
        push(a, pop(b));
    }
}

void pb(Stack* a, Stack* b) {
    if (!isEmpty(a)) {
        push(b, pop(a));
    }
}

void ra(Stack* a) {
    if (a->top > 0) {
        int temp = a->arr[a->top];
        for (int i = a->top; i > 0; i--) {
            a->arr[i] = a->arr[i - 1];
        }
        a->arr[0] = temp;
    }
}

void rb(Stack* b) {
    if (b->top > 0) {
        int temp = b->arr[b->top];
        for (int i = b->top; i > 0; i--) {
            b->arr[i] = b->arr[i - 1];
        }
        b->arr[0] = temp;
    }
}

void rr(Stack* a, Stack* b) {
    ra(a);
    rb(b);
}

void rra(Stack* a) {
    if (a->top > 0) {
        int temp = a->arr[0];
        for (int i = 0; i < a->top; i++) {
            a->arr[i] = a->arr[i + 1];
        }
        a->arr[a->top] = temp;
    }
}

void rrb(Stack* b) {
    if (b->top > 0) {
        int temp = b->arr[0];
        for (int i = 0; i < b->top; i++) {
            b->arr[i] = b->arr[i + 1];
        }
        b->arr[b->top] = temp;
    }
}

void rrr(Stack* a, Stack* b) {
    rra(a);
    rrb(b);
}

