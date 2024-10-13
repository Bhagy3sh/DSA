// Problem: Find the shortest path from a source vertex to all other vertices in a non-negative weighted graph using Dijkstra's Algorithm
// Solution:

#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int n, adj[MAX][MAX];

void Dijkstra(int src) {
    int dist[MAX], visited[MAX];

    // Initialize distances and visited status
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    
    dist[src] = 0;

    // Dijkstra's Algorithm
    for (int count = 0; count < n - 1; count++) {
        int min = INF, u;

        // Find the minimum distance vertex
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }

        visited[u] = 1;

        // Update distances
        for (int v = 0; v < n; v++) {
            if (!visited[v] && adj[u][v] && dist[u] != INF && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    // Output the shortest distances
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int edges, v1, v2, weight, src;

    // Input: Number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Input: Adjacency matrix representation of the graph
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (v1 v2 weight): ");
        scanf("%d%d%d", &v1, &v2, &weight);
        adj[v1][v2] = adj[v2][v1] = weight;
    }

    // Input: Source vertex
    printf("Enter source vertex: ");
    scanf("%d", &src);

    // Perform Dijkstra's Algorithm
    Dijkstra(src);

    return 0;
}
