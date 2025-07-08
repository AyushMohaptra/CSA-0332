#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, weight;
} Edge;

int parent[MAX], rank[MAX];

// Find root of a vertex with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Union by rank
void unionSet(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);

    if (xroot != yroot) {
        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }
}

// Compare function for qsort
int compare(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->weight - e2->weight;
}

void kruskal(Edge edges[], int V, int E) {
    Edge mst[MAX];
    int mstWeight = 0, count = 0;

    // Sort edges by weight
    qsort(edges, E, sizeof(Edge), compare);

    // Initialize DSU
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    printf("Edges in the Minimum Spanning Tree:\n");

    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            mst[count++] = edges[i];
            mstWeight += edges[i].weight;
            printf("%d - %d : %d\n", u, v, edges[i].weight);
            unionSet(u, v);
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);
}

int main() {
    int V, E;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    Edge edges[MAX];
    printf("Enter edges in format: u v weight\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskal(edges, V, E);

    return 0;
}
