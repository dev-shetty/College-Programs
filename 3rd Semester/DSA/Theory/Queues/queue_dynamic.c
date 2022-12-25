#include <stdio.h>
#include <stdlib.h>
int *queue = NULL;
int front, rear;
int size;

int isFull() {
    if (rear == size - 1) return 1;
    return 0;
}

int isEmpty() {
    if (front == -1 || front > rear) return 1;
    return 0;
}

void createQueue() {
    if (!queue) {
        front = rear = -1;
        printf("Enter the size of queue: ");
        scanf("%d", &size);
        queue = (int *)malloc(size * sizeof(int));
    } else {
        printf("Queue already exist! \n");
    }
}

void enqueue() {
    int item;
    if (isFull()) {
        printf("Queue Overflow \n");
    } else if (!queue)
        printf("Queue not defined yet! \n");
    else {
        printf("Enter the element to be inserted: ");
        scanf("%d", &item);
        if (front == -1) front++;
        rear++;
        *(queue + rear) = item;
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow \n");
    } else if (!queue)
        printf("Queue not defined yet! \n");
    else {
        if (!queue) printf("Queue not defined yet! \n");
        printf("%d has been removed \n", *(queue + front));
        front++;
    }
}

void display() {
    int i;
    if (isEmpty()) {
        printf("Queue Underflow \n");
    } else if (!queue)
        printf("Queue not defined yet! \n");
    else {
        if (!queue) printf("Queue not defined yet! \n");
        printf("Queue elements are: \n");
        for (i = front; i <= rear; i++) {
            printf("%d ", *(queue + i));
        }
        printf("\n");
    }
}

void deleteQueue() {
    if (!queue) {
        printf("Queue doesn't exist... Create one! \n");
    } else {
        free(queue);
        queue = NULL;
        printf("Queue Deleted! \n");
    }
}

void main() {
    int choice;
    while (1) {
        printf("\n******** QUEUE OPERATIONS ********\n");
        printf("1. CREATE QUEUE \n");
        printf("2. ENQUEUE \n");
        printf("3. DEQUEUE \n");
        printf("4. DISPLAY \n");
        printf("5. DELETE QUEUE \n");
        printf("6. EXIT \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createQueue();
                break;
            case 2:
                enqueue();
                break;
            case 3:
                dequeue();
                break;
            case 4:
                display();
                break;
            case 5:
                deleteQueue();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid Choice \n");
                return;
        }
    }
}