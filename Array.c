#include <stdio.h>

int score[10] = {10, 20, 30, 40, 50};
int n = 5;

// INSERT - Insert data
void insert(int new_number, int position) {
    int i;
    if (position < 1 || position > n + 1) {
        printf("Invalid position!\n");
        return;
    }
    // Move existing elements to the right
    for (i = n; i >= position; i--) {
        score[i] = score[i - 1];
    }
    // Insert the new number
    score[position - 1] = new_number;
    n++;
    printf("Insert(%d, %d) -> %d added at position %d\n", new_number, position, new_number, position);
}

// TRAVERSE / DISPLAY - Display data
void display() {
    int i;
    printf("Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", score[i]);
    }
    printf("\n");
}

int main() {
    display();

    insert(60, 3);
    display();

    insert(70, 1);
    display();

    return 0;
}
