#include<stdio.h>
void TOH(int n, char x, char y, char z)
{
    if(n>0)
    {
        TOH(n-1,x,z,y);
        printf("%c to %c\n",x,y);
        TOH(n-1,z,y,x);
    }
}
void main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    TOH(n,'A','B','C');
}