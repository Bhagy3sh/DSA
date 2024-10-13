// Problem: Find the shortest path from a source vertex to all other vertices in a graph using Bellman-Ford Algorithm, which can handle negative weights
// Solution:

#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

struct Edge {
    int src, dest, weight;
};

int n, e;
struct Edge edges[MAX];

void BellmanFord(int src) {
    int dist[MAX];

    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    // Bellman-Ford Algorithm
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < e; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            printf("Graph contains a negative weight cycle\n");
            return;
        }
    }

    // Output the shortest distances
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int v1, v2, weight, src;

    // Input: Number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Input: Edge details
    for (int i = 0; i < e; i++) {
        printf("Enter edge (v1 v2 weight): ");
        scanf("%d%d%d", &v1, &v2, &weight);
        edges[i].src = v1;
        edges[i].dest = v2;
        edges[i].weight = weight;
    }

    // Input: Source vertex
    printf("Enter source vertex: ");
    scanf("%d", &src);

    // Perform Bellman-Ford Algorithm
    BellmanFord(src);

    return 0;
}
