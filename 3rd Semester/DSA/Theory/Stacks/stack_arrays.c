#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int stack[MAX], top = -1, item;

int isEmpty() {
    if (top == -1) return 1;
    return 0;
}

int isFull() {
    if (top == MAX - 1) return 1;
    return 0;
}

void push() {
    if (isFull())
        printf("Stack Overflow \n");
    else {
        printf("Enter the item to be inserted: ");
        scanf("%d", &item);
        stack[++top] = item;
    }
}
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow \n");
    } else {
        printf("%d is removed from the stack", stack[top]);
        top--;
    }
}
void display() {
    if (isEmpty()) {
        printf("Stack Underflow \n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
    }
}

void main() {
    int choice;
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