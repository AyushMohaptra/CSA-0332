#include <stdio.h>
#include <limits.h>

#define V 10  // Max number of cities

int tsp(int graph[V][V], int visited[], int pos, int n, int count, int cost, int start, int *minCost) {
    if (count == n && graph[pos][start]) {
        if (cost + graph[pos][start] < *minCost)
            *minCost = cost + graph[pos][start];
        return *minCost;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[pos][i]) {
            visited[i] = 1;
            tsp(graph, visited, i, n, count + 1, cost + graph[pos][i], start, minCost);
            visited[i] = 0; // Backtrack
        }
    }
    return *minCost;
}

int main() {
    int graph[V][V], n;
    int visited[V] = {0};
    int minCost = INT_MAX;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix (0 if no path):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    visited[0] = 1;  // Start from city 0
    tsp(graph, visited, 0, n, 1, 0, 0, &minCost);

    if (minCost == INT_MAX)
        printf("No possible tour found.\n");
    else
        printf("Minimum cost to complete the tour: %d\n", minCost);

    return 0;
}
