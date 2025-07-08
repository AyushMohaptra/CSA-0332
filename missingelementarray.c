#include <stdio.h>

int findMissing(int arr[], int n) {
    int total = (n + 1) * (n + 2) / 2;  // Sum of 1 to (n + 1)
    for (int i = 0; i < n; i++)
        total -= arr[i];
    return total;
}

int main() {
    int arr[] = {1, 3, 5, 4, 6, 2, 8};  // Missing 7
    int n = sizeof(arr) / sizeof(arr[0]);

    int missing = findMissing(arr, n);
    printf("The missing element is: %d\n", missing);

    return 0;
}
