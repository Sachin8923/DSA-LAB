#include <stdio.h>
#define SIZE 5
int queue[SIZE], front = -1, rear = -1;

void enqueue(int val) {
    if ((rear + 1) % SIZE == front) printf("Circular Queue Overflow\n");
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = val;
    }
}

void dequeue() {
    if (front == -1) printf("Circular Queue Underflow\n");
    else {
        printf("Dequeued: %d\n", queue[front]);
        if (front == rear) front = rear = -1;
        else front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) printf("Queue is empty\n");
    else {
        int i = front;
        do {
            printf("%d ", queue[i]);
            i = (i + 1) % SIZE;
        } while (i != (rear + 1) % SIZE);
        printf("\n");
    }
}

int main() {
    enqueue(1); enqueue(2); enqueue(3); enqueue(4);
    display(); dequeue(); display();
    return 0;
}
