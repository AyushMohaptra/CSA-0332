#include <stdio.h>

void sort(int arr[], int n) {
    // Simple Bubble Sort to sort before Binary Search
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {23, 5, 87, 14, 9, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 14;

    printf("Original array: ");
    printArray(arr, n);

    // Linear Search
    int linResult = linearSearch(arr, n, key);
    if (linResult != -1)
        printf("Linear Search: Element %d found at index %d\n", key, linResult);
    else
        printf("Linear Search: Element %d not found\n", key);

    // Sort and perform Binary Search
    sort(arr, n);
    printf("Sorted array for Binary Search: ");
    printArray(arr, n);

    int binResult = binarySearch(arr, n, key);
    if (binResult != -1)
        printf("Binary Search: Element %d found at index %d\n", key, binResult);
    else
        printf("Binary Search: Element %d not found\n", key);

    return 0;
}
