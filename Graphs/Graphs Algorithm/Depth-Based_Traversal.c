// Problem: Perform Depth-First Search (DFS) traversal on a graph
// Solution:

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], n;

void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            DFS(i);
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
        printf("Enter edge %d (v1 v2): ", i+15);
        scanf("%d%d", &v1, &v2);
        adj[v1][v2] = adj[v2][v1] = 1;
    }

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Perform DFS traversal
    printf("DFS traversal starting from vertex 0: ");
    DFS(0);

    return 0;
}
