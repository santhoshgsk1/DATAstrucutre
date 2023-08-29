#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

bool isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, int value) {
    if (!isFull(stack)) {
        stack->top++;
        stack->arr[stack->top] = value;
        printf("%d pushed to the stack.\n", value);
    } else {
        printf("Stack is full. Cannot push %d.\n", value);
    }
}

int pop(struct Stack *stack) {
    if (!isEmpty(stack)) {
        int poppedValue = stack->arr[stack->top];
        stack->top--;
        return poppedValue;
    } else {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
}

int peek(struct Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top];
    } else {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 5);
    push(&stack, 10);
    push(&stack, 15);

    printf("Top element: %d\n", peek(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Top element: %d\n", peek(&stack));

    return 0;
}

