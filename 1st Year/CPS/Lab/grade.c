#include<stdio.h>
void main()
{
    int avg;
    printf("Enter your average: ");
    scanf("%d",&avg);
    if (avg>=80 && avg<=100)
    {
        printf("Your Grade is Honours (H)");
    }
    else if(avg>=60 && avg<=79)
    {
        printf("Your grade is 1st Class");
    }
    else if(avg>=50 && avg<=59)
    {
        printf("Your Grade is 2nd Class");
    }
    else if(avg>=40 && avg<=49)
    {
        printf("Your grade is 3rd Class");
    }
    else
    {
        printf("You failed!!");
    }
}