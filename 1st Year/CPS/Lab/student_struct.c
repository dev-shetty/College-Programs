#include<stdio.h>
struct student
{
    char name[25];
    float marks1;
    float marks2;
    float marks3;
};

void main()
{
    struct student s[10];
    int n, i;
    float average[i];
    printf("Enter the number of students: ");
    scanf("%d",&n);
    printf("Enter the student details \n");
    for(i=0;i<n;i++)
    {
        printf("Enter the students name: ");
        scanf("%s", s[i].name);
        printf("Enter the students marks in 1 subject: ");
        scanf("%f", &s[i].marks1);
        printf("Enter the students marks in 2 subject: ");
        scanf("%f", &s[i].marks2);
        printf("Enter the students marks in 3 subject: ");
        scanf("%f", &s[i].marks3);
        printf("\n");
        average[i] = (s[i].marks1 + s[i].marks2 + s[i].marks3)/3;
    }
    printf("The students details are: \n");
    for(i=0;i<n;i++)
    {
        printf("Student name: %s\n", s[i].name);
        printf("Student's average = %f\n", average[i]);
        if(average[i]>=50)
            printf("Student scored above average marks!\n");
        else
            printf("Student scored below average marks!\n");
    }
    
}