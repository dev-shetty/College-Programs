/*
 * 1) Design and implement a program in C on frequency histogram that fills a frequency array 
 * for data values in the range 1 - n, and then prints their histogram
 ? The program should 
 * a) Read, store and print the data in an array
 * b) Analyse tge data in the array, one element at a time. Add 1 to the corresponding element
 * in a frequency array based on the data value.
 * c) Print the histogram using asterisks fot each occurences of an element
 * 
 ? Sample Output
    Enter the number of array elements: 8
    Enter the 1D array elements it must be ranging from 0-9 
    1 9 6 5 9 8 1 2 
    Array elements are: 
    1       9       6       5       9       8       1       2
    Frequency Histogram is:
    Histogram Frequency:
    [0]
    [1]     *       *
    [2]     *
    [3]
    [4]
    [5]     *
    [6]     *
    [7]
    [8]     *
    [9]     *       *
 */

#include<stdio.h>
#include<stdlib.h>
int a[100], i, j, n;
int frequency[10] = {0};
void getData();
void printData();
void makeFrequency();
void makeHistogram();

void main() {
getData();
printData();
makeFrequency();
makeHistogram();
}

void getData() {
    printf("Enter the number of array elements: ");
    scanf("%d", &n);
    printf("Enter the 1D array elements it must be ranging from 0-9 \n");
    for (i = 0; i < n; i++) 
        scanf("%d", &a[i]);
}

void printData() {
    if(n==0) {
        printf("Array is empty \n");
        exit(0);
    }
    printf("Array elements are: \n");
    for(i=0; i<n; i++)
        printf("%d\t", a[i]);
}

void makeFrequency() {
    for(i=0; i<10; i++)
        for(j=0; j<n;j++)
            if(a[j] == i)
                frequency[i] ++;
}

void makeHistogram() {
    printf("\nFrequency Histogram is: \n");
    printf("Histogram Frequency: \t");
    for(i=0; i<10; i++) {
        printf("\n [%d]", i);
        for(j=0; j<frequency[i]; j++)
            printf("\t *");
    }
    printf("\n");
}