#include<stdio.h>
int fact (int k)
{
    if (k>0)
        return (k*fact(k-1));
    else
        return 1 ;
}
void main()
{
    int n ;
    printf("Enter the number of which you want factorial : ");
    scanf("%d",&n);
    printf("%d",fact(n));
}

