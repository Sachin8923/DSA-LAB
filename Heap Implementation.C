#include <stdio.h>

#define MAX 100
int heap[MAX];
int size = 0;

void swap(int* a, int* b) {
    int t = *a; *a = *b; *b = t;
}

void insert(int val) {
    heap[++size] = val;
    int i = size;
    while (i > 1 && heap[i] < heap[i / 2]) {
        swap(&heap[i], &heap[i / 2]);
        i = i / 2;
    }
}

void display() {
    for (int i = 1; i <= size; i++) printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(10); insert(5); insert(30); insert(2); insert(7);
    printf("Min-Heap: ");
    display();
    return 0;
}
