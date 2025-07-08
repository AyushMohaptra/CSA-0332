#include <stdio.h>

int main() {
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {5, 6, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int result[size1 + size2];

    // Copy elements from arr1
    for (int i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }

    // Copy elements from arr2
    for (int i = 0; i < size2; i++) {
        result[size1 + i] = arr2[i];
    }

    // Display result
    printf("Concatenated array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
