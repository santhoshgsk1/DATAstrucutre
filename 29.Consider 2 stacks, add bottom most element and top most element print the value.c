#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;
void initialize(Stack *stack) {
    stack->top = -1;
}
int isEmpty(Stack *stack) {
    return stack->top == -1;
}
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full, cannot push element.\n");
        return;
    }
    stack->items[++stack->top] = value;
}
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot pop element.\n");
        return -1;
    }
    return stack->items[stack->top--];
}

int main() {
    Stack stack1, stack2;
    initialize(&stack1);
    initialize(&stack2);
    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);
    push(&stack2, 40);
    push(&stack2, 50);
    push(&stack2, 60);
    int sum = pop(&stack1) + pop(&stack2);

    printf("Sum of bottom-most and top-most elements: %d\n", sum);

    return 0;
}

