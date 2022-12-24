#include <stdio.h>
#include <stdlib.h>
int *stack = NULL;
int top = -1, size;

int isEmpty() {
    if (top == -1) return 1;
    return 0;
}

int isFull() {
    if (top == size - 1) return 1;
    return 0;
}

void createStack() {
    if (!stack) {
        printf("Enter the size of stack: ");
        scanf("%d", &size);
        stack = (int *)malloc(size * sizeof(int));
        printf("Stack of size %d created! \n", size);
    } else {
        printf("Stack already exists! \n");
    }
}

void push() {
    if (isFull()) {
        printf("Stack Overflow \n");
    } else {
        int item;
        printf("Enter the element to be inserted: ");
        scanf("%d", &item);
        top++;
        *(stack + top) = item;
    }
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow \n");
    } else {
        printf("%d has been popped out \n", *(stack + top));
        top--;
    }
}

void display() {
    int i;
    if (isEmpty()) {
        printf("Stack Underflow \n");
    } else {
        printf("The stack elements are: \n");
        for (i = top; i >= 0; i--) {
            printf("%d ", *(stack + i));
        }
        printf("\n");
    }
}

void deleteStack() {
    if (!stack) {
        printf("Stack is not defined yet! \n");
    } else {
        free(stack);
        stack = NULL;
        top = -1;
        printf("Stack deleted \n");
    }
}

void peek() {
    if (!stack)
        printf("Stack not defined yet! \n");
    else if (isEmpty())
        printf("Stack Underflow \n");
    else
        printf("stack[top] is %d \n", *(stack + top));
}

void main() {
    int choice;
    while (1) {
        printf("\n******** STACK OPERATIONS ********\n");
        printf("1. CREATE STACK \n");
        printf("2. PUSH \n");
        printf("3. POP \n");
        printf("4. DISPLAY \n");
        printf("5. PEEK \n");
        printf("6. DELETE STACK \n");
        printf("7. EXIT \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createStack();
                break;
            case 2:
                push();
                break;
            case 3:
                pop();
                break;
            case 4:
                display();
                break;
            case 5:
                peek();
                break;
            case 6:
                deleteStack();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid Choice \n");
                return;
        }
    }
}