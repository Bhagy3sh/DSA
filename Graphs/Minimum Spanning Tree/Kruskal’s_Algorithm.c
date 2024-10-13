// Problem: Find the Minimum Spanning Tree (MST) of a graph using Kruskal’s Algorithm
// Solution:

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int src, dest, weight;
};

struct Edge edges[MAX], mst[MAX];
int n, e, parent[MAX];

int compare(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->weight - edgeB->weight;
}

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void Kruskal() {
    int mstWeight = 0;
    int mstIndex = 0;

    // Sort edges based on weight
    qsort(edges, e, sizeof(edges[0]), compare);

    // Initialize parent array
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    // Kruskal's Algorithm
    for (int i = 0; i < e; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        if (find(u) != find(v)) {
            mst[mstIndex++] = edges[i];
            unionSet(u, v);
            mstWeight += edges[i].weight;
        }
    }

    // Output the Minimum Spanning Tree
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < mstIndex; i++) {
        printf("%d -- %d == %d\n", mst[i].src, mst[i].dest, mst[i].weight);
    }
    printf("Total weight of MST: %d\n", mstWeight);
}

int main() {
    int v1, v2, weight;

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

    // Perform Kruskal's Algorithm
    Kruskal();

    return 0;
}
