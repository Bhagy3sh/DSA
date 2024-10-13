// Problem: Perform Breadth-First Search (BFS) traversal on a graph
// Solution:

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], n;

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0, i;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int edges, v1, v2;

    // Input: Number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Input: Adjacency matrix representation of the graph
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (v1 v2): ", i+1);
        scanf("%d%d", &v1, &v2);
        adj[v1][v2] = adj[v2][v1] = 1;
    }

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Perform BFS traversal
    printf("BFS traversal starting from vertex 0: ");
    BFS(0);

    return 0;
}
