// Problem: Find the Minimum Spanning Tree (MST) of a graph using Prim’s Algorithm
// Solution:

#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int n, adj[MAX][MAX], parent[MAX], key[MAX], mstSet[MAX];

int minKey() {
    int min = INF, minIndex;

    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void Prim() {
    // Initialize arrays
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    // Start from the first vertex
    key[0] = 0;
    parent[0] = -1;

    // Prim's Algorithm
    for (int count = 0; count < n - 1; count++) {
        int u = minKey();
        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !mstSet[v] && adj[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adj[u][v];
            }
        }
    }

    // Output the Minimum Spanning Tree
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 1; i < n; i++) {
        printf("%d -- %d == %d\n", parent[i], i, adj[i][parent[i]]);
    }
}

int main() {
    int edges, v1, v2, weight;

    // Input: Number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = INF;
        }
    }

    // Input: Edges and their weights
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (v1 v2 weight): ");
        scanf("%d%d%d", &v1, &v2, &weight);
        adj[v1][v2] = adj[v2][v1] = weight;
    }

    // Perform Prim's Algorithm
    Prim();

    return 0;
}

