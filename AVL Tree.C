#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key, height;
    struct Node *left, *right;
} Node;

int height(Node *N) {
    return N ? N->height : 0;
}

Node* create(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key; node->left = node->right = NULL; node->height = 1;
    return node;
}

int max(int a, int b) { return a > b ? a : b; }

int getBalance(Node *N) {
    return N ? height(N->left) - height(N->right) : 0;
}

Node* rotateRight(Node* y) {
    Node *x = y->left, *T2 = x->right;
    x->right = y; y->left = T2;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

Node* rotateLeft(Node* x) {
    Node *y = x->right, *T2 = y->left;
    y->left = x; x->right = T2;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

Node* insert(Node* node, int key) {
    if (!node) return create(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    else return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // Balancing
    if (balance > 1 && key < node->left->key) return rotateRight(node);
    if (balance < -1 && key > node->right->key) return rotateLeft(node);
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);
    inorder(root);
    return 0;
}
