#include<stdio.h>
void main()
{
    int i=1,j,p=1;
    do
    {
        j = 1;
        do
        {
            p = i * j;
            printf("%d\t",p);
            j++;

        } while(j<=10);
        printf("\n");
        i++;
    } while(i<=12);
}