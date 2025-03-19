#include<stdio.h>
void main(void)
{
    //defining variables
    int a= 5,b =7;
    //adding with call by value
    int sum1 = a+b;
    printf("%d ",sum1);
    //adding with call by reference
    int *p_a = &a, *p_b = &b;
    int sum2;
    int *p_sum2 = &sum2;
    *p_sum2 = *p_a + *p_b;
    printf("%d",sum2);

}
