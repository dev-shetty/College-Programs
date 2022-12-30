#include <stdio.h>
#include <stdlib.h>
struct node {
    int item;
    struct node* rlink;
    struct node* llink;
};
typedef struct node* NODE;
NODE start = NULL;

NODE createNode() {
    NODE newNode;
    newNode = (NODE)malloc(sizeof(NODE));
    printf("Enter the item to be inserted: ");
    scanf("%d", &newNode->item);
    newNode->llink = NULL;
    newNode->rlink = NULL;
    return newNode;
}

void insertFront() {
    NODE newNode = createNode();
    if (start == NULL) {
        start = newNode;
    } else {
        newNode->rlink = start;
        newNode->llink = NULL;
        start = newNode;
    }
}

void deleteFront() {
    NODE temp;
    if (start == NULL) {
        printf("List is Empty \n");
    } else if (start->rlink == NULL) {
        printf("%d has been deleted \n", start->item);
        free(start);
        start = NULL;
    } else {
        temp = start;
        start = start->rlink;
        temp->rlink = NULL;
        temp->llink = NULL;
        printf("%d has been deleted \n", temp->item);
        free(temp);
        temp = NULL;
    }
}

void insertEnd() {
    NODE newNode, current;
    newNode = createNode();
    if (start == NULL) {
        start = newNode;
    } else {
        current = start;
        while (current->rlink != NULL) {
            current = current->rlink;
        }
        current->rlink = newNode;
        newNode->llink = current;
    }
}

void deleteEnd() {
    NODE current;
    if (start == NULL) {
        printf("List is Empty \n");
    } else if (start->rlink == NULL) {
        printf("%d has been deleted \n", start->item);
        free(start);
        start = NULL;
    } else {
        current = start;
        while (current->rlink != NULL) {
            current = current->rlink;
        }
        current->llink->rlink = NULL;
        current->llink = NULL;
        printf("%d has been deleted \n", current->item);
        free(current);
        current = NULL;
    }
}

void display() {
    NODE current = start;
    if (current == NULL) {
        printf("List is empty \n");
    } else {
        printf("The list elements are: ");
        while (current != NULL) {
            printf("%d ", current->item);
            current = current->rlink;
        }
        printf("\n");
    }
}

void main() {
    int choice;
    while (1) {
        printf("\n******** DOUBLY LINKED LIST OPERATIONS ********\n");
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