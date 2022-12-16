#include<stdio.h>
void main()
{
    char gender;
    float balance,bonus;
    printf("Enter your gender M/F: ");
    scanf("%c",&gender);
    printf("Enter balance: ");
    scanf("%f",&balance);
    if(gender == 'F')
    {
        if (balance>=5000)
        {
            bonus = 0.05*balance;
        }
        else
        {
            bonus = 0.02*balance;
        }
    }
    else
    {
        bonus = 0.02*balance;
    }
    
    printf("Bonus = %f",bonus);
    balance = balance + bonus;
}