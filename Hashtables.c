#include <stdio.h>
#define CAPACITY 10

int hash_table[CAPACITY];

// Hash Function
int hashFunction(int key) {
    return key % CAPACITY;
}

// INSERT - Insert Student ID
void insert(int value) {
    int index = hashFunction(value);
    int start = index;

    // Linear Probing - if collision, move to next
    while (hash_table[index] != -1) {
        printf("Insert(%d) -> index %d Collision! Moving to next\n", value, index);
        index = (index + 1) % CAPACITY;
        if (index == start) {
            printf("Hash Table is Full!\n");
            return;
        }
    }
    hash_table[index] = value;
    printf("Insert(%d) -> %d inserted in index %d\n", value, value, index);
}

// TRAVERSE / DISPLAY
void display() {
    int i;
    printf("Hash Table:\n");
    for (i = 0; i < CAPACITY; i++) {
        if (hash_table[i] == -1) {
            printf("Index %d : Empty\n", i);
        }
        else {
            printf("Index %d : %d\n", i, hash_table[i]);
        }
    }
}

int main() {
    int i;
    for (i = 0; i < CAPACITY; i++) {
        hash_table[i] = -1;
    }

    insert(23);
    insert(45);
    insert(12);
    insert(67);
    insert(34);
    insert(89);
    insert(90);
    insert(33);
    insert(77);
    display();

    return 0;
}
