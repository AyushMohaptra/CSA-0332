#include <stdio.h>

int main() {
    int arr[] = {4, 5, 6, 4, 2, 5, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int visited[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Repeated numbers and their counts:\n");
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1;
            }
        }
        if (count > 1)
            printf("%d -> %d times\n", arr[i], count);
    }

    return 0;
}
