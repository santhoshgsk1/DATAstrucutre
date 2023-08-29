#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *createNode(int data) {
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct TreeNode *insert(struct TreeNode *root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}
struct TreeNode *search(struct TreeNode *root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
struct TreeNode *findMin(struct TreeNode *root) {
    if (root == NULL || root->left == NULL)
        return root;
    return findMin(root->left);
}
struct TreeNode *findMax(struct TreeNode *root) {
    if (root == NULL || root->right == NULL)
        return root;
    return findMax(root->right);
}

int main() {
    struct TreeNode *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    int key_to_search = 40;
    struct TreeNode *search_result = search(root, key_to_search);
    if (search_result != NULL)
        printf("Element %d found in the tree.\n", key_to_search);
    else
        printf("Element %d not found in the tree.\n", key_to_search);

    struct TreeNode *min_element = findMin(root);
    printf("Minimum element in the tree: %d\n", min_element->data);

    struct TreeNode *max_element = findMax(root);
    printf("Maximum element in the tree: %d\n", max_element->data);

    return 0;
}

