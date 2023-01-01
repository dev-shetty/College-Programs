/*
* 5) Design and implement a program in C for the following operations on singly
* circular linked list (SCLL) with header nodes.
* a) Represent and evaluate a polynomial.
* b) Find the sum of two polynomial A and B and store the result in C.

! Note:
! to compile use gcc polynomial.c -lm
! to execute ./a.out

? Sample input:
    Enter the elements of polynomial A
    Enter the coefficient and exponents in decreasing order: 2 3 2 1
    Do you want to enter more coefficients (Y/N): y
    Enter the coefficient and exponents in decreasing order: 2 2 2 1
    Do you want to enter more coefficients (Y/N): y
    Enter the coefficient and exponents in decreasing order: 3 1 1 1
    Do you want to enter more coefficients (Y/N): y
    Enter the coefficient and exponents in decreasing order: 1 0 0 0
    Do you want to enter more coefficients (Y/N): n

? Example

    A: 2*x^3*y^2*z^1 + 2*x^2*y^2*z^1 + 3*x^1*y^1*z^1 + 1*x^0*y^0*z^0
    B: 3*x^4*y^3*z^1 + 3*x^2*y^2*z^1 + 9*x^1*y^1*z^1 + 8*x^0*y^0*z^0

 => C: 3*x^4*y^3*z^1 + 2*x^3*y^2*z^1 + 5*x^2*y^2*z^1 + 12*x^1*y^1*z^1 +
       9*x^0*y^0*z^0

    Evaluation when x: 2, y:1, z: 3
    Result : 333
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct polynomial {
    int coef, x, y, z;
    struct polynomial* next;
};
typedef struct polynomial* NODE;

NODE getNode() {
    NODE x;
    x = (NODE)malloc(sizeof(struct polynomial));
    return x;
}

NODE readPolynomial() {
    NODE temp, head, current;
    char ch;
    head = getNode();
    head->coef = -1;
    head->x = -1;
    head->y = -1;
    head->z = -1;
    head->next = head;
    do {
        temp = getNode();
        printf("Enter the coefficient and exponents in decreasing order: ");
        scanf("%d%d%d%d", &temp->coef, &temp->x, &temp->y, &temp->z);
        current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = temp;
        temp->next = head;
        printf("Do you want to enter more coefficients (Y/N): ");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');
    return head;
}

void print(NODE ptr) {
    NODE current;
    current = ptr->next;
    while (current != ptr) {
        printf("%d*x^%d*y^%d*z^%d", current->coef, current->x, current->y,
               current->z);
        current = current->next;
        if (current != ptr) {
            printf(" + ");
        }
    }
}

int compare(NODE a, NODE b) {
    if (a->x > b->x)
        return 1;
    else if (a->x < b->x)
        return -1;
    else if (a->y > b->y)
        return 1;
    else if (a->y < b->y)
        return -1;
    else if (a->z > b->z)
        return 1;
    else if (a->z < b->z)
        return -1;
    return 0;
}

void attach(int cf, int x1, int y1, int z1, NODE* ptr) {
    NODE temp = getNode();
    temp->coef = cf;
    temp->x = x1;
    temp->y = y1;
    temp->z = z1;
    (*ptr)->next = temp;
    *ptr = temp;
}

NODE addPolynomial(NODE a, NODE b) {
    NODE start_a, c, last_c;
    int sum, done = 0;
    start_a = a;
    a = a->next;
    b = b->next;
    c = getNode();
    c->coef = -1;
    c->x = -1;
    c->y = -1;
    c->z = -1;
    last_c = c;
    do {
        switch (compare(a, b)) {
            case -1:
                attach(b->coef, b->x, b->y, b->z, &last_c);
                b = b->next;
                break;
            case 0:
                if (start_a == a)
                    done = 1;
                else {
                    sum = a->coef + b->coef;
                    if (sum) attach(sum, a->x, a->y, a->z, &last_c);
                    a = a->next;
                    b = b->next;
                }
                break;
            case 1:
                if (start_a == a) done = 1;
                attach(a->coef, a->x, a->y, a->z, &last_c);
                a = a->next;
                break;
        }
    } while (!done);
    last_c->next = c;
    return c;
}

void evaluate(NODE ptr) {
    int res = 0;
    int x, y, z, ex, ey, ez, coef;
    NODE current;
    printf("Enter the values of x, y, z: ");
    scanf("%d%d%d", &x, &y, &z);
    current = ptr->next;
    while (current != ptr) {
        ex = current->x;
        ey = current->y;
        ez = current->z;
        coef = current->coef;
        res += coef * pow(x, ex) * pow(y, ey) * pow(z, ez);
        current = current->next;
    }
    printf("Result : %d \n", res);
}

void main() {
    int i, ch;
    NODE a, b, c;
    while (1) {
        printf("\n1. Represent first polynomial A \n");
        printf("2. Represent second polynomial B \n");
        printf("3. Display the polynomial A \n");
        printf("4. Display the polynomial B \n");
        printf("5. Add A and B polynomials \n");
        printf("6. Evaluate polynomial C \n");
        printf("7. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the elements of polynomial A \n");
                a = readPolynomial();
                break;
            case 2:
                printf("Enter the elements of polynomial B \n");
                b = readPolynomial();
                break;
            case 3:
                print(a);
                break;
            case 4:
                print(b);
                break;
            case 5:
                c = addPolynomial(a, b);
                printf("The sum of two polynomials is: ");
                print(c);
                printf("\n");
                break;
            case 6:
                evaluate(c);
                break;
            case 7:
                return;
            default:
                printf("Invalid Choice!!! \n");
        }
    }
}