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
    printf("%d",fact(5));
}
