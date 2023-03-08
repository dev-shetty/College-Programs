#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct tree {
    char name[20], phone[10];
    struct tree *leftChild, *rightChild;
};

int deflag = 0;
typedef struct tree* NODE;

NODE createNode() {
    NODE newNode = (NODE)malloc(sizeof(struct tree));
    printf("Enter the name: ");
    scanf("%s", newNode->name);
    printf("Enter the phone no.: ");
    scanf("%s", newNode->phone);
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

void insertBST(NODE root, NODE newNode) {
    if (strcmp(newNode->name, root->name) == 0) {
        printf("Key already exists \n");
        return;
    } else if (strcmp(newNode->name, root->name) < 0) {
        if (root->leftChild == NULL) {
            root->leftChild = newNode;
        } else {
            insertBST(root->leftChild, newNode);
        }
    } else {
        if (root->rightChild == NULL) {
            root->rightChild = newNode;
        } else {
            insertBST(root->rightChild, newNode);
        }
    }
}

NODE getRightMin(NODE root) {
    NODE temp = root;
    while (temp->leftChild != NULL) {
        temp = temp->leftChild;
    }
    return temp;
}

int search(NODE root, char key[]) {
    if (!root) return -1;
    if (strcmp(key, root->name) == 0)
        return 1;
    else if (strcmp(key, root->name) < 0) {
        search(root->leftChild, key);
    } else {
        search(root->rightChild, key);
    }
}

NODE deleteBST(NODE root, char keyName[]) {
    if (!root) {
        deflag = 1;
        return NULL;
    }
    if (strcmp(keyName, root->name) < 0) {
        root->leftChild = deleteBST(root->leftChild, keyName);
    } else if (strcmp(keyName, root->name) > 0) {
        root->rightChild = deleteBST(root->rightChild, keyName);
    } else {
        if (root->leftChild == NULL && root->rightChild == NULL) {
            free(root);
            return NULL;
        } else if (root->leftChild == NULL) {
            NODE temp = root->leftChild;
            free(root);
            return temp;
        } else {
            NODE rightMin = getRightMin(root->rightChild);
            strcpy(root->name, rightMin->name);
            strcpy(root->phone, rightMin->phone);
            root->rightChild = deleteBST(root->rightChild, rightMin->name);
        }
    }
    return root;
}

void inOrder(NODE temp) {
    if (temp) {
        inOrder(temp->leftChild);
        printf("| %s | %s |", temp->name, temp->phone);
        inOrder(temp->rightChild);
    }
}
void preOrder(NODE temp) {
    if (temp) {
        printf("| %s | %s |", temp->name, temp->phone);
        preOrder(temp->leftChild);
        preOrder(temp->rightChild);
    }
}
void postOrder(NODE temp) {
    if (temp) {
        postOrder(temp->leftChild);
        postOrder(temp->rightChild);
        printf("| %s | %s |", temp->name, temp->phone);
    }
}

void main() {
    int choice, n, keyFound = 0;
    char keyName[20];
    NODE root = NULL, newNode;
    printf("\n-------------------- CREATING A BST --------------------\n");
    printf("Enter the number of records in BST: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        newNode = createNode();
        if (!root) {
            root = newNode;
        } else {
            insertBST(root, newNode);
        }
    }
    while (1) {
        choice = 0;
        printf("\n--------------- MENU ---------------\n");
        printf("1. Search a list for a specified name \n");
        printf("2. Insert a new name \n");
        printf("3. Delete an exisiting name \n");
        printf("4. Traverse the phone list \n");
        printf("5. Exit \n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the key to be searched: ");
                scanf("%s", keyName);
                keyFound = search(root, keyName);
                if (keyFound == 1) {
                    printf("Name: %s is found in the BST \n", keyName);
                } else {
                    printf("Name: %s is not found in the BST \n", keyName);
                }
                break;

            case 2:
                newNode = createNode();
                if (!root) {
                    root = newNode;
                } else {
                    insertBST(root, newNode);
                }
                break;

            case 3:
                if (!root) {
                    printf("Tree is empty \n");
                } else {
                    deflag = 0;
                    printf("Enter the name to be deleted: ");
                    scanf("%s", keyName);
                    root = deleteBST(root, keyName);
                    if (deflag == -1) {
                        printf("Name: %s is not found in the BST \n", keyName);
                    } else {
                        printf("Name: %s is deleted from the BST \n", keyName);
                    }
                }
                break;

            case 4:
                if (!root) {
                    printf("Tree is empty \n");
                } else {
                    printf("\n PreOrder Traversal \n");
                    preOrder(root);
                    printf("\n InOrder Traversal \n");
                    inOrder(root);
                    printf("\n PostOrder Traversal \n");
                    postOrder(root);
                }
                break;
            case 5:
                exit(0);

            default:
                printf("Invalid choice \n");
                exit(0);
        }
    }
}