#include <stdio.h>

int main() {
    int arr[] = {10, 25, 36, 47, 58, 69, 72};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (n >= 5)
        printf("5th iterated element is: %d\n", arr[4]);
    else
        printf("Array has fewer than 5 elements.\n");

    return 0;
}
