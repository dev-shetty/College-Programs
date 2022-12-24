#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int queue[SIZE];
int front = -1, rear = -1;

int isEmpty() {
    if (rear == -1 || front > rear) return 1;
    return 0;
}
int isFull() {
    if (rear == SIZE - 1) return 1;
    return 0;
}

void enqueue() {
    int item;
    if (isFull()) {
        printf("Queue Overflow \n");
    } else {
        printf("Enter the element to be inserted: ");
        scanf("%d", &item);
        queue[++rear] = item;
        if (front == -1) front++;
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow \n");
    } else {
        printf("%d is removed from queue \n", queue[front]);
        front++;
    }
}

void display() {
    int i;
    if (isEmpty()) {
        printf("Queue Underflow \n");
    } else {
        printf("Queue elements are: \n");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void main() {
    int choice;
    while (1) {
        printf("\n******** QUEUE OPERATIONS ********\n");
        printf("1. ENQUEUE \n");
        printf("2. DEQUEUE \n");
        printf("3. DISPLAY \n");
        printf("4. EXIT \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice \n");
                return;
        }
    }
}