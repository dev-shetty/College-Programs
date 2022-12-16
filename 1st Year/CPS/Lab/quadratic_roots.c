#include<stdio.h>
#include<math.h>
void main()
{
    int a, b, c; 
    float D, root1, root2;
    printf("Enter the value of a b and c: ");
    scanf("%d%d%d",&a, &b, &c);
    D = sqrt(b*b - (4*a*c));
    if(D>0)
    {
        root1 = (-b + D)/(2*a);
        root2 = (-b - D)/(2*a);
        printf("The roots are %f and %f", root1, root2);
    }
    else if(D==0)
    {
        root1 = -b/(2*a);
        printf("Roots are equal and value is %d", root1);
    }
    else
    {
        printf("Roots are imaginary");
    }
}