// Problem: Find the shortest path between all pairs of vertices using Floyd-Warshall Algorithm
// Solution:

#include <stdio.h>

#define MAX 100
#define INF 99999

int n, adj[MAX][MAX];

void FloydWarshall() {
    int dist[MAX][MAX];

    // Initialize the distance matrix with adjacency matrix values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = adj[i][j];
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Output the shortest distances
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                printf("%7s", "INF");
            } else {
                printf("%7d", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int edges, v1, v2, weight;

    // Input: Number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix with INF for no connection
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                adj[i][j] = 0;
            } else {
                adj[i][j] = INF;
            }
        }
    }

    // Input: Edges and their weights
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (v1 v2 weight): ");
        scanf("%d%d%d", &v1, &v2, &weight);
        adj[v1][v2] = weight;
    }

    // Perform Floyd-Warshall Algorithm
    FloydWarshall();

    return 0;
}
