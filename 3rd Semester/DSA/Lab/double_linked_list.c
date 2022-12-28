/*
 * 4) Design and implement a menu driven program in C for the
 * following operations on doubly linked list (DLL) of student data with the
 * fields: usn, name, department, marks, phone no.
 * a) Create a DLL of n students data by using end insertion.
 * b) Display the status of DLL and count the number of nodes in it.
 * c) Perform insertion and deletion at the end of DLL.
 * d) Perform insertion and deletion at the front of DLL.
 * e) Display the total and average marks for each student.

 */

#include <stdio.h>
#include <stdlib.h>
int count;
struct node {
    float marks1, marks2, marks3;
    char usn[10], name[20], dept[20], phno[15];
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE start = NULL;
NODE getNode() {
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    return x;
}

NODE createNode() {
    NODE newNode;
    newNode = getNode();
    printf("\n--------------- Enter Students Details ---------------- \n");
    printf("Enter USN: ");
    scanf("%s", newNode->usn);
    printf("Enter Name: ");
    scanf("%s", newNode->name);
    printf("Enter Department: ");
    scanf("%s", newNode->dept);
    printf("Enter Marks1: ");
    scanf("%f", &(newNode->marks1));
    printf("Enter Marks2: ");
    scanf("%f", &(newNode->marks2));
    printf("Enter Marks3: ");
    scanf("%f", &(newNode->marks3));
    printf("Enter Phone No.: ");
    scanf("%s", newNode->phno);
    newNode->llink = NULL;
    newNode->rlink = NULL;
    count++;
    return newNode;
}

void displayDeleted(NODE deletedNode) {
    printf("The following student detail has been deleted \n");
    printf("USN | Name | Dept | Marks 1 | Marks 2 | Marks 3 | Phone No.\n");
    printf("--------------------------------------------------------------\n");
    printf("%s | %s | %s | %.2f | %.2f | %.2f | %s \n", deletedNode->usn,
           deletedNode->name, deletedNode->dept, deletedNode->marks1,
           deletedNode->marks2, deletedNode->marks3, deletedNode->phno);
    count--;
}

void insertFront() {
    NODE newNode;
    newNode = createNode();
    if (start == NULL) {
        start = newNode;
    } else {
        newNode->rlink = start;
        newNode->llink = NULL;
        start = newNode;
    }
}

void deleteFront() {
    NODE deletedNode;
    if (start == NULL) {
        printf("List is empty \n");
    } else if (start->rlink == NULL) {
        displayDeleted(deletedNode);
        free(start);
        start = NULL;
    } else {
        deletedNode = start;
        displayDeleted(deletedNode);
        start = start->rlink;
        deletedNode->rlink = NULL;
        deletedNode->llink = NULL;
        free(deletedNode);
        deletedNode = NULL;
    }
}

void insertRear() {
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

void deleteRear() {
    NODE current;
    if (start == NULL) {
        printf("List is empty \n");
    } else if (start->rlink == NULL) {
        displayDeleted(start);
        free(start);
        start = NULL;
    } else {
        current = start;
        while (current->rlink != NULL) {
            current = current->rlink;
        }
        displayDeleted(current);
        current->llink->rlink = NULL;
        current->llink = NULL;
        free(current);
        current = NULL;
    }
}

void display() {
    NODE current;
    float total, average;
    if (start == NULL) {
        printf("List is empty \n");
    } else {
        current = start;
        printf("The student details in doubly linked list from beginning \n");
        printf(
            "USN | Name | Dept | Marks 1 | Marks 2 | Marks 3 | Total Marks | "
            "Average | Phone No.\n");
        printf(
            "------------------------------------------------------------------"
            "--------------\n");
        while (current != NULL) {
            total = current->marks1 + current->marks2 + current->marks3;
            average = total / 3;
            printf("%s | %s | %s | %.2f | %.2f | %.2f | %.2f | %.2f | %s \n",
                   current->usn, current->name, current->dept, current->marks1,
                   current->marks2, current->marks3, total, average,
                   current->phno);
            current = current->rlink;
        }
        printf(
            "------------------------------------------------------------------"
            "--------------\n");
        printf("Number of Nodes: %d \n", count);
    }
}

void main() {
    int choice, i, n;
    while (1) {
        choice = 0;
        printf("\n-------------------- MENU --------------------\n");
        printf("1. Create a DLL of N student by using END Insertion \n");
        printf("2. Display Status and Count of Nodes \n");
        printf("3. Insertion at rear \n");
        printf("4. Deletion at rear \n");
        printf("5. Insertion at front \n");
        printf("6. Deletion at front \n");
        printf("7. Exit \n");
        printf("-----------------------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter number of student: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    insertRear();
                }
                break;
            case 2:
                display();
                break;
            case 3:
                insertRear();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                insertFront();
                break;
            case 6:
                deleteFront();
                break;
            case 7:
                return;
            default:
                printf("Invalid choice \n");
                return;
        }
    }
}