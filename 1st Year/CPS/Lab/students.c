#include<stdio.h>
void main()
{
    int n, roll_no, tele_no,i;
    char name[25],branch[25];
    printf("Enter the number of students: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\nEnter the students name: ");
        scanf("%s",name);
        printf("Enter %s's roll no.: ",name);
        scanf("%d",&roll_no);
        printf("Enter the branch: ");
        scanf("%s",branch);
        printf("Enter telephone no.: ");
        scanf("%d",&tele_no);
        
        printf("\nStudent's name: %s",name);
        printf("\n%s's roll no.: %d",name,roll_no);
        printf("\n%s's branch: %s",name,branch);
        printf("\n%s's telephone no.: %d\n",name,tele_no);
        printf("\n");
    }  
}