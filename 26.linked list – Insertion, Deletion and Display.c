#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertFront(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void deleteNode(struct Node **head, int value) {
    struct Node *current = *head;
    struct Node *prev = NULL;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element %d not found in the list.\n", value);
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

void display(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;

    insertFront(&head, 3);
    insertFront(&head, 2);
    insertFront(&head, 1);

    printf("Linked list after insertions: ");
    display(head);

    deleteNode(&head, 2);

    printf("Linked list after deletion: ");
    display(head);

    // Free allocated memory
    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

