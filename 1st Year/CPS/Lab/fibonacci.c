#include<stdio.h>
int fib(int);
void main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Fibonacci sequence is: \n");
    for(int i=0;i<n;i++)
        printf("%d\t",fib(i));
}
int fib(int x)
{
    if(x==0)
        return 0;
    else if(x==1)
        return 1;
    else
        return fib(x-1) + fib(x-2);
}