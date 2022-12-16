#include<stdio.h>
void main()
{
    int units,cust_no;
    float amount,z;
    printf("Enter your customer ID: ");
    scanf("%d",&cust_no);
    printf("Enter the no. of units consumed by the customer: ");
    scanf("%d",&units);
    if(units <= 200)
    {
        printf("You consumed %d units\n",units);
        amount = 0.50 * units;
        printf("Your amount to be paid is %f",amount);
    }
    else if(units >= 201 && units <=400)
    {
        printf("You consumed %d units\n",units);
        z = units - 200;
        amount = 100 + (0.65 * z);
        printf("Your amount to be paid is %f",amount);
    }
    else if(units>=401 && units<=600)
    {
        printf("You consumed %d units\n",units);
        z = units - 400;
        amount = 230 + (0.8 * z);
        printf("Your amount to be paid is %f",amount);
    }
    else
    {
        printf("You consumed %d units\n",units);
        z = units - 600;
        amount = 390 + (1 * z);
        printf("Your amount to be paid is %f",amount);
    }
}