#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}
void kthSmallestUtil(struct Node* root, int k, int* count, int* result) {
    if (root == NULL || *count >= k) {
        return;
    }
    
    kthSmallestUtil(root->left, k, count, result);
    
    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }
    
    kthSmallestUtil(root->right, k, count, result);
}

int kthSmallest(struct Node* root, int k) {
    int count = 0;
    int result = -1; 
    
    kthSmallestUtil(root, k, &count, &result);
    
    return result;
}

int main() {
    struct Node* root = NULL;
    
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    
    int k = 3;
    int kthMin = kthSmallest(root, k);
    
    printf("The %dth smallest element is: %d\n", k, kthMin);
    
    return 0;
}

