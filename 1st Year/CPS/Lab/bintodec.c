#include<stdio.h>
#include<math.h>
void main()
{
    int i, n, rem, dec=0;
    printf("Enter number in binary: ");
    scanf("%d",&n);
    for(i=0;n!=0;i++)
    {
        rem = n%2;
        if(rem!=0)
            dec += pow(2, i);
        n=n/10;
    }
    printf("Decimal number is: %d", dec);
}