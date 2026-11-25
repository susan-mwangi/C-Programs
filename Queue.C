#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Adding an element to the rear
void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue is Full!! Cannot enqueue %d\n", x);
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = x;
        printf("Value %d has been enqueued\n", x);
    }
}

//Removing an element from the front
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!! Nothing to Dequeue\n");
    } else {
        int x = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1; // Reset queue when last element is removed
        }
        printf("%d has been dequeued\n", x);
    }
}

//  TO JUMP
void jumpToFront(int pos) {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!!\n");
        return;
    }
    int targetIndex = front + pos - 1; // 1-based position from the current front
    if (targetIndex <= front || targetIndex > rear) {
        printf("Invalid jump position! Choose a position between 2 and %d\n", (rear - front + 1));
        return;
    }

    int jumpedValue = queue[targetIndex];
    // Shift elements right to make room at the front
    for (int i = targetIndex; i > front; i--) {
        queue[i] = queue[i - 1];
    }
    queue[front] = jumpedValue;
    printf("Value %d jumped to the front of the queue\n", jumpedValue);
}
// Updating a value at a specific position or searching for an old value
void update(int oldVal, int newVal) {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!!\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        if (queue[i] == oldVal) {
            queue[i] = newVal;
            printf("Updated %d to %d\n", oldVal, newVal);
            return;
        }
    }
    printf("Value %d not found in the queue\n", oldVal);
}

//displaying
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Current Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n\n");
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();

    update(20, 25);
    display();

    jumpToFront(3);
    display();

    dequeue();
    display();

    return 0;
}
