#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    char data;
    struct Node *next;
};

void insert(struct Node **head, char data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

bool isPalindrome(struct Node *head) {
    if (head == NULL || head->next == NULL) {
        return true; 
    }
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct Node *prev = NULL;
    struct Node *current = slow->next;
    struct Node *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    struct Node *firstHalf = head;
    struct Node *secondHalf = prev;

    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

int main() {
    struct Node *head = NULL;
    insert(&head, 'r');
    insert(&head, 'a');
    insert(&head, 'c');
    insert(&head, 'e');
    insert(&head, 'c');
    insert(&head, 'a');
    insert(&head, 'r');

    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }
    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

