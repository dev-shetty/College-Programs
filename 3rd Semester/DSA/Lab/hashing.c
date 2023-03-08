#include <stdio.h>
#include <stdlib.h>
int key, *hash_table, total_memory, total_records, hash_index, count = 0,
                                                               flag = 0;

void createHashTable() {
    printf("Enter the total number of memory: ");
    scanf("%d", &total_memory);
    printf("Enter the total number of records: ");
    scanf("%d", &total_records);

    hash_table = (int*)malloc(total_memory * sizeof(int));

    if (total_memory == 0) {
        printf("Cannot create hash table with 0 rows \n");
        return;
    } else {
        printf("Created hash table with %d rows \n", total_memory);
        for (int i = 0; i < total_memory; i++) {
            hash_table[i] = -1;
        }
    }
}

void insertKey(int key) {
    hash_index = key % total_memory;
    while (hash_table[hash_index] != -1) {
        hash_index = (hash_index + 1) % total_memory;
        flag = 1;
    }
    if (flag) {
        printf("Collision detected, and avoided by linear probing! \n");
        flag = 0;
    }
    hash_table[hash_index] = key;
    count++;
}

void displayHashTable() {
    if (!count) {
        printf("Hash table is empty \n");
        return;
    }
    printf("Hash Table Elements are: \n");
    for (int i = 0; i < total_memory; i++) {
        printf("[%d] --> %d \n", i, hash_table[i]);
    }
}

void main() {
    createHashTable();
    for (int i = 0; i < total_records; i++) {
        printf("Enter the record to be inserted: ");
        scanf("%d", &key);
        if (count == total_memory) {
            printf("Hash table is full \n");
            break;
        }
        insertKey(key);
    }
    displayHashTable();
}