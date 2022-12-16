#include<stdio.h>
void main()
{
    int loan1,loan2,loan3,max=100000,required;
    printf("Enter first loan amount: ");
    scanf("%d",&loan1);
    printf("Second loan amount: ");
    scanf("%d",&loan2);
    printf("Enter the loan amount you want: ");
    scanf("%d",&required);
    if(loan1==0 || loan2==0)
    {
        loan3 = max - loan1 - loan2;
        if(required <= loan3)
        printf("You can get loan");
        else
        printf("You can get loan upto %d",loan3);
    }
    else
    {
        printf("Pay your previous loans first! ");
    }

}


