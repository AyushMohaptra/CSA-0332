#include <stdio.h>
#include <stdlib.h>

// Define structure for a tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert element into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// Search for an element in BST
int search(struct Node* root, int key) {
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Find minimum element
int findMin(struct Node* root) {
    if (!root) return -1;
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

// Find maximum element
int findMax(struct Node* root) {
    if (!root) return -1;
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int main() {
    struct Node* root = NULL;
    int elements[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(elements)/sizeof(elements[0]);

    // Build BST
    for (int i = 0; i < n; i++)
        root = insert(root, elements[i]);

    // Search test
    int key = 60;
    if (search(root, key))
        printf("Element %d found in BST.\n", key);
    else
        printf("Element %d not found in BST.\n", key);

    printf("Minimum element in BST: %d\n", findMin(root));
    printf("Maximum element in BST: %d\n", findMax(root));

    return 0;
}
