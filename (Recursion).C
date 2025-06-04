#include <stdio.h>

// Fibonacci
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

// Tower of Hanoi
void TOH(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    TOH(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    TOH(n - 1, aux, to, from);
}

int main() {
    printf("Fibonacci(5): ");
    for (int i = 0; i < 5; i++) printf("%d ", fib(i));
    printf("\nTower of Hanoi with 3 disks:\n");
    TOH(3, 'A', 'C', 'B');
    return 0;
}
