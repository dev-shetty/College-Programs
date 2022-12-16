#include<stdio.h>
void main()
{
    int n, m, roll_no, total, marks, i, j, avg;
    printf("Enter the number of students & subjects: ");
    scanf("%d%d",&n, &m);
    for(i=1;i<=n;i++)
    {
        printf("\nEnter the roll no.: ");
        scanf("%d",&roll_no);
        total = 0;

        printf("Enter marks of %d subjects for roll no. %d: ",m,roll_no);
        for(j=1;j<=m;j++)
        {
            scanf("%d",&marks);
            total = total + marks;
        }
        printf("Total = %d\n",total);
        avg = total / m;

        if(avg>=85 && avg<=100)
            printf("Distinction\n");
        else if(avg>=70 && avg<=85)
            printf("First class\n");
        else if(avg>=50 && avg<=70)
            printf("Second class\n");
        else if(avg>=35 && avg<=50)
            printf("First class\n");
        else
            printf("Fail\n");
    }
}