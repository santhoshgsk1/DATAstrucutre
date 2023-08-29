#include <stdio.h>
#include <stdlib.h>
struct AVLNode {
    int data;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
};
int getHeight(struct AVLNode *node) {
    if (node == NULL)
        return -1;
    return node->height;
}
int getBalance(struct AVLNode *node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}
struct AVLNode *rotateRight(struct AVLNode *y) {
    struct AVLNode *x = y->left;
    struct AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + fmax(getHeight(y->left), getHeight(y->right));
    x->height = 1 + fmax(getHeight(x->left), getHeight(x->right));

    return x;
}
struct AVLNode *rotateLeft(struct AVLNode *x) {
    struct AVLNode *y = x->right;
    struct AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + fmax(getHeight(x->left), getHeight(x->right));
    y->height = 1 + fmax(getHeight(y->left), getHeight(y->right));

    return y;
}

// Function to create a new AVL node
struct AVLNode *createNode(int data) {
    struct AVLNode *newNode = (struct AVLNode *)malloc(sizeof(struct AVLNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 0;
    return newNode;
}

// Function to insert a new node into the AVL tree
struct AVLNode *insert(struct AVLNode *root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;  // Duplicate keys are not allowed

    root->height = 1 + fmax(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && data < root->left->data)
        return rotateRight(root);

    // Right Right Case
    if (balance < -1 && data > root->right->data)
        return rotateLeft(root);

    // Left Right Case
    if (balance > 1 && data > root->left->data) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && data < root->right->data) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}
void inorderTraversal(struct AVLNode *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct AVLNode *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Inorder traversal of the AVL tree: ");
    inorderTraversal(root);

    return 0;
}

