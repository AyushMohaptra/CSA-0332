#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key, height;
    struct Node *left, *right;
};

int max(int a, int b) { return a > b ? a : b; }

int height(struct Node *n) { return n ? n->height : 0; }

struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key; node->left = node->right = NULL; node->height = 1;
    return node;
}

struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left, *T2 = x->right;
    x->right = y; y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right, *T2 = y->left;
    y->left = x; x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(struct Node *n) {
    return n ? height(n->left) - height(n->right) : 0;
}

struct Node* insert(struct Node* n, int key) {
    if (!n) return newNode(key);
    if (key < n->key) n->left = insert(n->left, key);
    else if (key > n->key) n->right = insert(n->right, key);
    else return n;

    n->height = 1 + max(height(n->left), height(n->right));
    int b = getBalance(n);

    if (b > 1 && key < n->left->key) return rightRotate(n);
    if (b < -1 && key > n->right->key) return leftRotate(n);
    if (b > 1 && key > n->left->key) { n->left = leftRotate(n->left); return rightRotate(n); }
    if (b < -1 && key < n->right->key) { n->right = rightRotate(n->right); return leftRotate(n); }

    return n;
}

struct Node* minValue(struct Node* n) {
    while (n->left) n = n->left;
    return n;
}

struct Node* delete(struct Node* root, int key) {
    if (!root) return root;
    if (key < root->key) root->left = delete(root->left, key);
    else if (key > root->key) root->right = delete(root->right, key);
    else {
        if (!root->left || !root->right) {
            struct Node* temp = root->left ? root->left : root->right;
            free(root); return temp;
        }
        struct Node* temp = minValue(root->right);
        root->key = temp->key;
        root->right = delete(root->right, temp->key);
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int b = getBalance(root);

    if (b > 1 && getBalance(root->left) >= 0) return rightRotate(root);
    if (b > 1 && getBalance(root->left) < 0) { root->left = leftRotate(root->left); return rightRotate(root); }
    if (b < -1 && getBalance(root->right) <= 0) return leftRotate(root);
    if (b < -1 && getBalance(root->right) > 0) { root->right = rightRotate(root->right); return leftRotate(root); }

    return root;
}

struct Node* search(struct Node* root, int key) {
    if (!root || root->key == key) return root;
    return key < root->key ? search(root->left, key) : search(root->right, key);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 25);
    root = insert(root, 15);
    root = insert(root, 35);
    root = delete(root, 15);
    struct Node* found = search(root, 35);
    if (found) printf("Found\n");
    else printf("Not Found\n");
    return 0;
}
