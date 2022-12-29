#include <stdio.h>
#include <stdlib.h>
struct node {
    int item;
    struct node* next;
};
int count;
typedef struct node* NODE;
NODE start = NULL;

NODE createNode() {
    NODE newNode;
    newNode = (NODE)malloc(sizeof(struct node));
    printf("Enter the element to be inserted: ");
    scanf("%d", &newNode->item);
    newNode->next = NULL;
    count++;
    return newNode;
}

void insertFront() {
    NODE newNode;
    newNode = createNode();
    if (start == NULL) {
        start = newNode;
    } else {
        newNode->next = start;
        start = newNode;
    }
}

void deleteFront() {
    NODE temp;
    if (start == NULL) {
        printf("List is Empty \n");
    } else if (start->next == NULL) {
        printf("%d has been deleted \n", start->item);
        free(start);
        start = NULL;
    } else {
        temp = start;
        start = start->next;
        temp->next = NULL;
        free(temp);
    }
}

void insertEnd() {
    NODE newNode, current;
    newNode = createNode();
    if (start == NULL) {
        start = newNode;
    } else {
        current = start;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteEnd() {
    NODE current, prev;
    if (start == NULL) {
        printf("List is Empty \n");
    } else if (start->next == NULL) {
        free(start);
        start = NULL;
    } else {
        current = start;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        printf("%d has been deleted", current->item);
        prev->next = NULL;
        free(current);
    }
}

void display() {
    NODE temp;
    if (start == NULL) {
        printf("List is Empty");
    } else {
        temp = start;
        while (temp != NULL) {
            printf("%d ", temp->item);
            temp = temp->next;
        }
        printf("\n");
    }
}

void main() {
    int choice;
    while (1) {
        printf("\n******** SINGLY LINKED LIST OPERATIONS ********\n");
        printf("1. INSERT FRONT \n");
        printf("2. DELETE FRONT \n");
        printf("3. INSERT END \n");
        printf("4. DELETE END \n");
        printf("5. DISPLAY \n");
        printf("6. EXIT \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertFront();
                break;
            case 2:
                deleteFront();
                break;
            case 3:
                insertEnd();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid Choice \n");
                return;
        }
    }
}