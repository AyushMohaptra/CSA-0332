#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;  // Element found at index i
        }
    }
    return -1;  // Element not found
}

int main() {
    int arr[] = {23, 45, 12, 67, 89};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 67;

    int result = linearSearch(arr, size, key);

    if (result != -1)
        printf("Element %d found at index %d\\n", key, result);
    else
        printf("Element %d not found in the array\\n", key);

    return 0;
}
