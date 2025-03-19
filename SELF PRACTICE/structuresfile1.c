#include<stdio.h>

void main(void)
{
    int a = 10;
    int *p = &a;
    int **q;
    q = &p;
    printf("%d \n",*(*q));
    printf("%d",q-(int**)&p);
}
