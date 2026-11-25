#include <stdio.h>
#define MAX 6

int box[MAX];
int top = -1;

// PUSH - Insert
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack is full!\n");
    }
    else {
        top++;
        box[top] = x;
        printf("Push(%d) -> %d added\n", x, x);
    }
}

// POP - Delete
void pop() {
    int x;
    if (top == -1) {
        printf("Stack is empty!\n");
    }
    else {
        x = box[top];
        top--;
        printf("Pop() -> %d removed\n", x);
    }
}

// TRAVERSE / DISPLAY
void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty!\n");
    }
    else {
        printf("Stack: ");
        for (i = top; i >= 0; i--) {
            printf("%d ", box[i]);
        }
        printf("\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();

    return 0;
}
