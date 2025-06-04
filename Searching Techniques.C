#include <stdio.h>

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;
    return -1;
}

// Binary Search (array must be sorted)
int binarySearch(int arr[], int n, int key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

// Tree Search
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data; node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int data) {
    if (!root) return newNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

int searchTree(Node* root, int key) {
    if (!root) return 0;
    if (root->data == key) return 1;
    else if (key < root->data) return searchTree(root->left, key);
    else return searchTree(root->right, key);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Linear: %d\n", linearSearch(arr, n, 7));
    printf("Binary: %d\n", binarySearch(arr, n, 7));

    Node* root = NULL;
    root = insert(root, 10);
    insert(root, 5); insert(root, 15);
    printf("Tree Search (5): %d\n", searchTree(root, 5));
    return 0;
}
