#include <stdio.h>
void insert(int array[], int *size, int element, int position) {
    for (int i = *size; i > position; i--) {
        array[i] = array[i - 1];
    }
    array[position] = element;
    (*size)++;
}
void delete(int array[], int *size, int position) {
    if (*size <= 0) {
        printf("Array is empty, cannot delete element.\n");
        return;
    }
    for (int i = position; i < *size - 1; i++) {
        array[i] = array[i + 1];
    }
    (*size)--;
}
void display(int array[], int size) {
    if (size <= 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int main() {
    int array[100];
    int size = 0;
    int choice, element, position;

    while (1) {
        printf("\nArray Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (0-based index): ");
                scanf("%d", &position);
                insert(array, &size, element, position);
                break;
            case 2:
                printf("Enter position to delete (0-based index): ");
                scanf("%d", &position);
                delete(array, &size, position);
                break;
            case 3:
                display(array, size);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}