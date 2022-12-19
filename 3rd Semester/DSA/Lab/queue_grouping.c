/*
* 3) Design and implement a program in C to categorize the data. Consider the
* following sample list of numbers.
? Sample Input:
    3, 22, 12, 6, 10, 34, 65, 29, 9, 30, 81, 4, 5, 19, 20, 57, 44, 99

* Categorize and sort them into different groups as mentioned below:
? Output Format:
    Group 1: less than 10
    Group 2: between 10 and 20
    Group 3: between 20 and 29
    Group 4: 30 and greater
*/

#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 20

void insert_element();
void delete_element();
void display();
int queue[CAPACITY];
int rear = -1, front = -1;

void main() {
    int choice;
    while (1) {
        printf("\n ***** QUEUE OPERATIONS ***** \n");
        printf("1. INSERT \n");
        printf("2. DELETE \n");
        printf("3. DISPLAY \n");
        printf("4. QUIT \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert_element();
                break;
            case 2:
                delete_element();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong choice \n");
        }
    }
}

void insert_element() {
    int element;
    if (rear == CAPACITY - 1)
        printf("Queue is full \n");
    else {
        if (front == -1) front = 0;
        printf("Enter the element: ");
        scanf("%d", &element);
        rear++;
        queue[rear] = element;
    }
}

void delete_element() {
    if (front == -1 || front == rear) {
        printf("Queue is empty \n");
        return;
    } else {
        printf("Element deleted from the queue is %d \n", queue[front]);
        front++;
    }
}

void display() {
    int i;
    if (front == -1 || front == rear)
        printf("Queue is empty \n");
    else {
        printf("Queue elements are: \n");
        for (i = front; i <= rear; i++) {
            printf("%d", queue[i]);
        }
        printf("\n*******************************\n");
        printf("    CATEGORIZATION OF DATA     ");
        printf("\n*******************************\n");
        printf("Group 1: less than 10 - \n");
        for (i = front; i <= rear; i++) {
            if (queue[i] < 10) {
                printf("%d ", queue[i]);
            }
        }
        printf("\nGroup 2: Between 10 and 19 - \n");
        for (i = front; i <= rear; i++) {
            if (queue[i] >= 10 && queue[i] <= 19) {
                printf("%d ", queue[i]);
            }
        }
        printf("\nGroup 1: Between 20 and 29 - \n");
        for (i = front; i <= rear; i++) {
            if (queue[i] >= 20 && queue[i] <= 29) {
                printf("%d ", queue[i]);
            }
        }
        printf("\nGroup 1: 30 and Greater - \n");
        for (i = front; i <= rear; i++) {
            if (queue[i] >= 30) {
                printf("%d ", queue[i]);
            }
        }
        printf("\n");
    }
}