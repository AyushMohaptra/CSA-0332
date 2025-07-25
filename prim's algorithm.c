#include <stdio.h>
#include <limits.h>

#define V 100  // Maximum number of vertices

int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }

    return min_index;
}

void printMST(int parent[], int graph[V][V], int n) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V], int n) {
    int parent[V];     // Stores constructed MST
    int key[V];        // Used to pick minimum weight edge
    int mstSet[V];     // true if vertex is included in MST

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;       // Start from first vertex
    parent[0] = -1;   // First node is root

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    printMST(parent, graph, n);
}

int main() {
    int n, graph[V][V];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    primMST(graph, n);

    return 0;
}
