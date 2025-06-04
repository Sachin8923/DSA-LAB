#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next, *prev;
} Node;

Node* create(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val; n->next = n->prev = NULL;
    return n;
}

void displaySingly(Node* head) {
    printf("Singly: ");
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void displayDoubly(Node* head) {
    printf("Doubly: ");
    while (head) {
        printf("%d ", head->data);
        if (!head->next) break;
        head = head->next;
    }
    printf("\nReverse: ");
    while (head) {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}

int main() {
    // Singly Linked List
    Node *s1 = create(10), *s2 = create(20), *s3 = create(30);
    s1->next = s2; s2->next = s3;
    displaySingly(s1);

    // Doubly Linked List
    Node *d1 = create(1), *d2 = create(2), *d3 = create(3);
    d1->next = d2; d2->prev = d1;
    d2->next = d3; d3->prev = d2;
    displayDoubly(d1);
    return 0;
}
