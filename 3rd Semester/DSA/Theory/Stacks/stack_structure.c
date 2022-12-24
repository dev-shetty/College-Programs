#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct stack {
    int a[SIZE];
    int top;
};
struct stack s;

int isFull() {
    if (s.top == SIZE - 1) return 1;
    return 0;
}

int isEmpty() {
    if (s.top == -1) return 1;
    return 0;
}

void push() {
    int item;
    if (isFull()) {
        printf("Stack Overflow \n");
    } else {
        printf("Enter the item to be inserted: ");
        scanf("%d", &item);
        s.top++;
        s.a[s.top] = item;
    }
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow \n");
    } else {
        printf("%d has been popped out \n", s.a[s.top]);
        s.top--;
    }
}

void display() {
    int i;
    if (isEmpty()) {
        printf("Stack Underflow \n");
    } else {
        printf("Stack elements are: \n");
        for (i = s.top; i >= 0; i--) {
            printf("%d ", s.a[i]);
        }
    }
}

void main() {
    int choice;
    s.top = -1;
    while (1) {
        printf("\n******** QUEUE OPERATIONS ********\n");
        printf("1. PUSH \n");
        printf("2. POP \n");
        printf("3. DISPLAY \n");
        printf("4. EXIT \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
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