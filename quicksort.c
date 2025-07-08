#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Recursive Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partitioning index

        quickSort(arr, low, pi - 1);  // Sort left subarray
        quickSort(arr, pi + 1, high); // Sort right subarray
    }
}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {33, 21, 45, 12, 27, 89, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    display(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    display(arr, n);

    return 0;
}
