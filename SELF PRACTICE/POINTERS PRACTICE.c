#include<stdio.h>
int arrayuse(int *a, int size);
void main()
{
   int size = 5;
   int a[5] = {5,2,3,4,5};
   int sum = arrayuse(&a,size);
   printf("%d",sum);
}
int arrayuse(int *a,int size)
{
    int sum = 0;
    for(int i = 0; i<size; i++)
        sum = sum + *a++;
    return sum;
}
