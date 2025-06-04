#include <stdio.h>
#define MAX 5

int graph[MAX][MAX] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 1, 1},
    {0, 1, 1, 0, 1},
    {0, 0, 1, 1, 0}
};

int visited[MAX];

void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < MAX; i++)
        if (graph[v][i] && !visited[i])
            DFS(i);
}

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < MAX; i++) {
            if (graph[v][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

void resetVisited() {
    for (int i = 0; i < MAX; i++) visited[i] = 0;
}

int main() {
    printf("DFS: ");
    DFS(0);
    resetVisited();
    printf("\nBFS: ");
    BFS(0);
    return 0;
}
