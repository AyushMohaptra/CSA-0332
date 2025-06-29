#include <stdio.h>

int main() {
    int array[] = {1, 2, 3, 4, 5, 2, 6, 3, 7};
    int size = sizeof(array) / sizeof(array[0]);
    printf("Duplicate elements: ");
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] == array[j]) {
                int dup = 0;
                for (int k = 0; k < i; k++) {
                    if (array[k] == array[i]) {
                        dup = 1;
                        break;
                    }
                }
                if (!dup) {
                    printf("%d ", array[i]);
                }
                break;
            }
        }
    }

    return 0;
}
