// stack.h
#ifndef STACK_H
#define STACK_H

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack* stack);
int isEmpty(Stack* stack);
int isFull(Stack* stack);
void push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack* stack);

void sa(Stack* a);
void sb(Stack* b);
void ss(Stack* a, Stack* b);
void pa(Stack* a, Stack* b);
void pb(Stack* a, Stack* b);
void ra(Stack* a);
void rb(Stack* b);
void rr(Stack* a, Stack* b);
void rra(Stack* a);
void rrb(Stack* b);
void rrr(Stack* a, Stack* b);

#endif // STACK_H

