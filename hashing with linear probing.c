#include <stdio.h>
#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];
int currentSize = 0;

void initialize() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;  // -1 denotes empty
}

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    if (currentSize == TABLE_SIZE) {
        printf("Hash Table is full!\n");
        return;
    }

    int index = hash(key);

    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }

    hashTable[index] = key;
    currentSize++;
}

int search(int key) {
    int index = hash(key);
    int startIndex = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return index;

        index = (index + 1) % TABLE_SIZE;

        if (index == startIndex)
            break;  // We've looped all the way around
    }

    return -1;
}

void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1)
            printf("[%d] → %d\n", i, hashTable[i]);
        else
            printf("[%d] → ~\n", i);
    }
}

int main() {
    initialize();

    insert(23);
    insert(43);
    insert(13);
    insert(27);

    display();

    int key = 43;
    int result = search(key);
    if (result != -1)
        printf("Key %d found at index %d\n", key, result);
    else
        printf("Key %d not found in the table\n", key);

    return 0;
}
